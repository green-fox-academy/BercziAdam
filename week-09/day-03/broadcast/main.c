#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET clientToServer_socket;
    char buf[512];
    unsigned int fromLength;
    struct sockaddr_in Remote_Address, Server_Address;
    struct hostent *hostPointer;
    int message, checkCall;
    int broadcastOn = 1;
    int broadcastOff = 0;
    char *broadcastMessage;
    time_t clk;
    FILE *client_log;

    broadcastMessage = "TOTORO 15000";

    printf("Message %s\n", broadcastMessage);

    client_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
    if (client_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
        fprintf(client_log, "Failed. Error Code : %d\n\n",WSAGetLastError());
        return 1;
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Initialised.\n\n");
        fprintf(client_log, "Initialised.\n\n");
    }
    /*Create client socket*/
    if((clientToServer_socket = socket(AF_INET , SOCK_DGRAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
        fprintf(client_log, "Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Socket created.\n\n");
        fprintf(client_log, "Socket created.\n\n");
    }

    Remote_Address.sin_family=AF_INET;
    Remote_Address.sin_addr.s_addr = inet_addr("255.255.255.255");
    Remote_Address.sin_port=htons(1234);


   checkCall = setsockopt(clientToServer_socket, SOL_SOCKET, SO_BROADCAST, &broadcastOn, 4);
   if(checkCall == -1)
        perror("Error: Second setsockopt call failed");

   int broadcastMessageLen = strlen(broadcastMessage) + 1;

   printf("Message test %d\n", broadcastMessageLen);

   message = sendto(clientToServer_socket, broadcastMessage, broadcastMessageLen, 0, (struct sockaddr *) &Remote_Address, sizeof(Remote_Address));

   if (message ==-1)
        perror("Error: sendto call failed");

   close(clientToServer_socket);
     return 0;
}



