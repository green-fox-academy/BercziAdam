/* Includes ------------------------------------------------------------------*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* variables */
uint32_t Background_color;
uint16_t Screen_width;
uint16_t Screen_height;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
    osDelay(2000);
    LCD_UsrLog("srv ok\n");
    int master_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(5656);
    addr_in.sin_addr.s_addr = INADDR_ANY;
    struct sockaddr *addr = (struct sockaddr *)&addr_in;
    bind(master_sock, addr, sizeof(*addr));
    listen(master_sock, 1);
    struct sockaddr client_addr;
    int slave_sock = -1;
    uint32_t buff[5];
    while (1) {
    	while (accept(master_sock, &client_addr, NULL) < 0) {
			osDelay(1000);
		}

		LCD_UsrLog("accept ok \t slave_sock : %d\n", slave_sock);

        int received_bytes = 0;

        while (received_bytes > -1) {
			received_bytes = recv(slave_sock, buff, 5 * sizeof(uint32_t), 0);
			if (received_bytes > 0) {
				 BSP_LCD_SetTextColor(buff[2]);
				 BSP_LCD_FillCircle(buff[0], buff[1], buff[3]);

			}
        }

        closesocket(slave_sock);

    }//while
    closesocket(master_sock);

    while (1) {
        /* Delete the Init Thread */
        osThreadTerminate(NULL);
    }


}//thread

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
