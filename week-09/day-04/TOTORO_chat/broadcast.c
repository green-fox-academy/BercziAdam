#include "main.h"
#include "broadcast.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>

void broadcast_send_message()
{
    SOCKET clientToServer_socket;
    struct sockaddr_in Remote_Address;
    int message, checkCall;
    const char *broadcastOn = "1";
    char *broadcastMessage;
    time_t clk;

    broadcastMessage = "TOTORO 15000";

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

    printf("Message test %d\n", broadcastMessageLen);

    message = sendto(clientToServer_socket, broadcastMessage, broadcastMessageLen, 0, (struct sockaddr *) &Remote_Address, sizeof(Remote_Address));

    if (message ==-1)
        perror("Error: sendto call failed");

    closesocket(clientToServer_socket);
}

void broadcast_server()
{
    SOCKET server_socket;
    struct sockaddr_in server_address, client_address;
    int recv_bytes;
    int clientLength;
    char message[4096];
    const char s[] = " ";
    char *token;
    time_t clk;
    int in;

    if((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Could not create socket : %d\n\n", WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Socket created.\n\n");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(12345);

    if( bind(server_socket,(struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        printf("Bind failed with error code : %d\n\n", WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        puts("Bind done.\n");
    }

    user_index = 0;

    while(1) {

        clk = time(NULL);
        //printf("%s", ctime(&clk));
        puts("Waiting for incoming data... in broadcast\n");

        clientLength = sizeof(client_address);

        recv_bytes= recvfrom(server_socket, message, 4096, 0, (struct sockaddr*) &client_address, &clientLength);

        if(recv_bytes < 0) {
            clk = time(NULL);
           // printf("\n%s", ctime(&clk));
            puts("recv failed.\n");
        } else {
            clk = time(NULL);
           // printf("\n%s", ctime(&clk));
            printf("SERVER: read %d bytes from IP %s(%s)\n", recv_bytes,
                inet_ntoa(client_address.sin_addr), message);
        }


        token = strtok(message, s);

         if( token != NULL ) {

             token = strtok(NULL, s);
         }

        if(user_index == 0) {
            user_array[user_index].ip_address = client_address.sin_addr.s_addr;
            user_array[user_index].discovery_port_number = atoi(token);

            discovery_message();

            user_index++;
        } else {
            for (int i = 0; i < user_index; i++) {
                if(user_array[i].ip_address == client_address.sin_addr.s_addr) {
                    in = 1;
                    printf("after for %d \t %d\n", in, user_index);
                    break;
                } else {
                    in = 0;
                    printf("after for %d \t %d\n", in, user_index);
                }
            }
                printf("after for %d \t %d\n", in, user_index);
            }

        if (in == 0 && user_index != 0) {

            user_array[user_index].ip_address = client_address.sin_addr.s_addr;
            user_array[user_index].discovery_port_number = atoi(token);

            discovery_message();

            user_index++;
        }
    }
    closesocket(server_socket);
}

