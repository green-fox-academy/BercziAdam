#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>
int main()
{

    WSADATA wsa;
    SOCKET clientToServer_socket;
    struct sockaddr_in Remote_Address;
    int message, checkCall;
    const char *broadcastOn = "1";
    char *broadcastMessage;
    time_t clk;
    char key;

    clk = time(NULL);
    printf("%s", ctime(&clk));
    printf("Initialising Winsock...\n\n");

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Initialised.\n\n");
    }


    broadcastMessage = "marharepa 54545";

    printf("Message %s\n", broadcastMessage);

    if((clientToServer_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Could not create socket : %d\n\n", WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Socket created.\n\n");
    }

    Remote_Address.sin_family=AF_INET;
    Remote_Address.sin_addr.s_addr = inet_addr("255.255.255.255");
    Remote_Address.sin_port=htons(12345);


    checkCall = setsockopt(clientToServer_socket, SOL_SOCKET, SO_BROADCAST, broadcastOn, 4);
    if(checkCall == -1)
        perror("Error: Second setsockopt call failed");

    int broadcastMessageLen = strlen(broadcastMessage) + 1;

     while(1) {

            if (kbhit()) {

                key =getch();

                switch(key) {
                case 'm' :
                    message = sendto(clientToServer_socket, broadcastMessage, broadcastMessageLen, 0, (struct sockaddr *) &Remote_Address, sizeof(Remote_Address));

                    if (message ==-1)
                        perror("Error: sendto call failed");

                        printf("sent");
                    break;
                }
            }
     }

    closesocket(clientToServer_socket);
}
