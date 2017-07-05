/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
 typedef struct {
	int32_t x;
	int32_t y;
 } coordinate_t;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define RADIUS  5
#define DATA_BUFFER_SIZE 5
#define SERVER_IP  "10.27.6.113"
#define SERVER_PORT 24862
 /* Private variables ---------------------------------------------------------*/
 TS_StateTypeDef ts_state;
 TS_StateTypeDef *ts_state_ptr = &ts_state;

 /* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
 void socket_client_thread(void const *argument)
 {
     osDelay(5000);
     int client_socket;
     client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
     struct sockaddr_in addr_in;
     addr_in.sin_family = AF_INET;
     addr_in.sin_port = htons(SERVER_PORT);
     addr_in.sin_addr.s_addr = inet_addr(SERVER_IP);
     int connected = -1;
     LCD_UsrLog("start to connect");

     uint32_t buff[DATA_BUFFER_SIZE];
     buff[2] = LCD_COLOR_DARKMAGENTA;
     buff[3] = RADIUS;
     buff[4] = LCD_COLOR_MAGENTA;
     while (1) {

    	while (connect(client_socket, (struct sockaddr *)&addr_in, sizeof(addr_in)) < 0) {
    		LCD_UsrLog("Trying to connect...\n");
			osDelay(1000);
    	}

    	LCD_UsrLog("connected to %s:%d connected:%d\n", SERVER_IP, SERVER_PORT, connected);

    	int send_bytes = 1;
		do {
			if (BSP_PB_GetState(BUTTON_KEY))
				 BSP_LCD_Clear(LCD_COLOR_MAGENTA);

			BSP_TS_GetState(ts_state_ptr);
			if (ts_state.touchDetected) {
				 // Draw

				if (ts_state_ptr->touchX[0] < 420 - RADIUS    &&
					ts_state_ptr->touchX[0] > RADIUS      &&
					ts_state_ptr->touchY[0] < 272 - RADIUS    &&
					ts_state_ptr->touchY[0] > RADIUS) {
					BSP_LCD_SelectLayer(0);
					BSP_LCD_FillCircle(ts_state_ptr->touchX[0], ts_state_ptr->touchY[0], RADIUS);
					buff[0] = (uint32_t)ts_state_ptr->touchX[0];
					buff[1] = (uint32_t)ts_state_ptr->touchY[0];

				}
				send_bytes = send(client_socket, buff, DATA_BUFFER_SIZE * sizeof(uint32_t), 0);
				LCD_UsrLog("%d asd\n", send_bytes);
			}//touch_detect
		} while (send_bytes > 0);
		closesocket(client_socket);
     }//while

 }//thread

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
