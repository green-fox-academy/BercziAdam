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
	// Server address structure initialization
	struct sockaddr_in addr_in;                                 // Inet address structure definition
	addr_in.sin_family = AF_INET;                               // This address is an internet address
	addr_in.sin_port = htons(SERVER_PORT);                      // Server port
	addr_in.sin_addr.s_addr = INADDR_ANY;   		            // Server IP
	struct sockaddr *addr = (struct sockaddr *)&addr_in;        // Make a struct sockaddr pointer, which points to the address stucture

	// Creating the socket
	int master_sock = socket(PF_INET, SOCK_STREAM, 0);
	// Check if socket is ok
	if (master_sock < 0)
		LCD_ErrLog("socket problemos ");

	// Start binding the socket to the previously set address
	int flag = bind(master_sock, addr, sizeof(*addr));
	// Check if the binding is ok
	if (flag < 0)
		LCD_UsrLog("bind() ");

	// Start listening on with the set socket with a predefined queue size
	flag = listen(master_sock, SERVER_QUEUE_SIZE);
	// Check is listening is ok
	if (flag < 0)
		LCD_UsrLog("listen() ");

	LCD_UsrLog("Server is initialized, waiting for connections at %lu:%d\n", INADDR_ANY, SERVER_PORT);

	// Create variables which will be used in the while loop
	struct sockaddr client_addr;    // Client address structure
	int slave_sock;              // Slave socket definition, this will be used to store the incoming socket
	char buff[SERVER_BUFF_LEN];                // Buffer for incoming and outgoing data
	int cntr = 1;                   // Counter for incoming connections

	// Set starting things
	Background_color = LCD_COLOR_WHITE;
	Screen_width = (uint16_t)BSP_LCD_GetXSize();
	Screen_height = (uint16_t)BSP_LCD_GetYSize();

	while (1)
	{
		// Accept the connection and save the incoming socket
		slave_sock = accept(master_sock, &client_addr, NULL);
		// Check if the socket is valid
		if (slave_sock < 0)
			LCD_UsrLog("accept problem");

		//printf("%d. connection accepted\n", cntr);

		// Receive the data sent by the client
		int received_bytes;
		do {
			received_bytes = recv(slave_sock, buff, SERVER_BUFF_LEN, 0);
			if (received_bytes == 0) {
				printf("Connection closed, waiting for an other connection!\n");
			} else if (received_bytes < 0) {
				printf("Something went wrong with the client socket, trying to close it...\n");
				break;
			} else {
				// Terminate the string with zero
				buff[received_bytes] = '\0';
				// Print out the received data
				//LCD_UsrLog("Received string: %s \n", buff);
				// Send back the received string
				send(slave_sock, buff, received_bytes, 0);

				message_handler(buff);

			}
		} while (received_bytes > 0);

		closesocket(slave_sock);
		printf("%d. client socket closed\n\n", cntr);
		cntr++;
		osDelay(10);
	}
}

void client_paints(uint16_t x, uint16_t y, uint16_t radius, uint32_t color) {

	if ((x - radius) < 0 || (x + radius) > Screen_width || (y - radius) < 0 || (y + radius) > Screen_height) {
		return;
	}
	else {
		BSP_LCD_SetTextColor(color);
		BSP_LCD_FillCircle(x, y, radius);
	}
}

void message_handler (char *message) {

	const char s[2] = "$";
	char *str_ptr;

	str_ptr = strtok(message, s);

	if (*str_ptr == 'p') {

		// Load the global variables
		str_ptr = strtok(NULL, s);
		uint16_t X = (uint16_t)atoi(str_ptr);
		str_ptr = strtok(NULL, s);
		uint16_t Y = (uint16_t)atoi(str_ptr);
		str_ptr = strtok(NULL, s);
		uint16_t Radius = (uint16_t)atoi(str_ptr);
		str_ptr = strtok(NULL, s);
		uint32_t Color = strtol(str_ptr, NULL, 16);
		Color += 0xFF000000;
		client_paints(X, Y, Radius, Color);

	} else if (*str_ptr == 'c') {

		str_ptr = strtok(NULL, s);

		if (*str_ptr == 'x') {
			BSP_LCD_Clear(Background_color);
		} else if (*str_ptr == 'b') {
			LCD_UsrLog("kAkamaka");
		} else {
			BSP_LCD_Clear(Background_color);
			BSP_LCD_DisplayStringAt(30, 30, "Problemos commandos / commandos", 2);
		}

	} else {
		BSP_LCD_Clear(Background_color);
		BSP_LCD_DisplayStringAt(30, 30, "Problemos commandos", 2);
	}
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
