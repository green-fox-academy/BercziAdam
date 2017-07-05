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
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_client_thread(void const *argument)
{

	struct sockaddr_in server;
	int s;
	char message[256];
	TS_StateTypeDef TS_State;
	TS_State.touchDetected = 0;
	TS_State.touchX[0] = 0;
	TS_State.touchY[0] = 0;
	coordinate_t samu;

	if((s = socket(AF_INET , SOCK_STREAM , 0)) < 0) {
		LCD_ErrLog("Could not create socket");
	} else {
		LCD_UsrLog("Socket created.\n\n");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("10.27.6.113");
	server.sin_port = htons(24862);

	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
		LCD_ErrLog("connect error client message.");
		return;
	} else {
		LCD_UsrLog("Connected!\n");
	}


	while(1) {

		BSP_TS_GetState(&TS_State);
		while(TS_State.touchDetected == 1) {

			samu.x = TS_State.touchX[0];
			samu.y = TS_State.touchY[0];

			//LCD_UsrLog("%d \t %d\n", samu.x, samu.y);

		    strcpy(message, "p$");
		    char str[10];

		    itoa(samu.x, str, 10);
		    strcat(message, str);
		    strcat(message, "$");

		    //LCD_UsrLog("%s\n", message);


		    itoa(samu.y, str, 10);
		    strcat(message, str);
		    strcat(message, "$");

			//LCD_UsrLog("%s\n", message);

		    strcat(message, "15");
		    strcat(message, "$");

			//LCD_UsrLog("%s\n", message);

			strcat(message, "0000FF");

			//LCD_UsrLog("%s\n", message);


			if( send(s , message , strlen(message) , 0) < 0)
			{
				//LCD_ErrLog("Send failed");
			}
			BSP_TS_GetState(&TS_State);
		}
	}
	closesocket(s);
	while (1) {
		/* Delete the Init Thread */
		osThreadTerminate(NULL);
	 }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
