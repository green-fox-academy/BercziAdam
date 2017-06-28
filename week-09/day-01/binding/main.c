#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    SOCKET new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char message[4096];


    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("10.27.6.195");
    server.sin_port = htons( 8888 );

    //Bind

    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
    }

    puts("Bind done");

    //Listen to incoming connections
    listen(s , 3);

    //Accept an incoming connection
    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    new_socket = accept(s , (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
    }

    puts("Connection accepted");

    while(1) {
        char client_reply[4096];
        int recv_bytes = recv(new_socket , client_reply , 4096 , 0);

        if(recv_bytes == SOCKET_ERROR) {
            puts("recv failed");
        } else {
            printf("client:\t");
            client_reply[recv_bytes] = '\0'; //Add a NULL terminating character to make it a proper string before printing
            puts(client_reply);
        }
        printf("server:\t");
        gets(message);
        message[strlen(message)] = '\0';
        if( send(new_socket , message , strlen(message) , 0) < 0) { //Reply to client
            puts("Send failed");
        }


    }
    if (new_socket == INVALID_SOCKET) {
        printf("accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }
    closesocket(s);
    WSACleanup();

    return 0;
}
