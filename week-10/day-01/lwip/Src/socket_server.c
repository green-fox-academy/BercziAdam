/* Includes ------------------------------------------------------------------*/

#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"

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
    int s;
    int new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char buffer[256];
    int recv_bytes;
    char message[256];

    if((s = socket(AF_INET , SOCK_STREAM , 0)) < 0) {
        LCD_ErrLog("Error.\n");
    } else {
        LCD_UsrLog("Socket created.\n\n");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) < 0) {
        LCD_ErrLog("Bind failed\n");
    } else {
        LCD_UsrLog("Bind done.\n");
    }

	listen(s, SERVER_QUEUE_SIZE);

	c = sizeof(struct sockaddr_in);

	LCD_UsrLog("Waiting for incoming connections...\n");

	new_socket = accept(s , (struct sockaddr *)&client, &c);

	if (new_socket < 0) {
			LCD_ErrLog("accept failed\n");
		} else {
			LCD_UsrLog("Connection accepted.\n");
		}

	while(1) {

		recv_bytes= recv(new_socket , buffer , 256 , 0);

        if(recv_bytes < 0) {
            LCD_ErrLog("recv failed.\n");
        } else {
            LCD_UsrLog("client:\t");
            buffer[recv_bytes] = '\0';
            LCD_UsrLog("%s\n", buffer);
        }

		strcpy(message, buffer);
		message[strlen(message)] = '\0';

		if( send(new_socket , message , strlen(message) , 0) < 0) {
			LCD_ErrLog("Send failed\n");
		}
	}
    closesocket(s);
}

void socket_broadcast_server_thread(void const *argument)
{


}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
