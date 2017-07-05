/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SOCKET_SERVER_H
#define __SOCKET_SERVER_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void socket_server_thread(void const *argument);

#define SERVER_PORT            56565
#define SERVER_QUEUE_SIZE    2
#define SERVER_BUFF_LEN        100

#endif /* __SOCKET_SERVER_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
