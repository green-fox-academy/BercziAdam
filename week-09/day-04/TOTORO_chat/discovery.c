#include "main.h"
#include "discovery.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>

void discovery_server()
{
    SOCKET s;
    SOCKET new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char client_reply[4096];
    char *token;
    int recv_bytes;
    time_t clk;

    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Socket created.\n\n");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(15000);

    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        printf("Bind failed with error code : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        puts("Bind done.\n");
    }



    while(1) {

        listen(s , 50);

        clk = time(NULL);
        //printf("%s", ctime(&clk));
        //puts("Waiting for incoming connections...\n");

        c = sizeof(struct sockaddr_in);

        new_socket = accept(s, (struct sockaddr *)&client, &c);

        if (new_socket == INVALID_SOCKET) {
            clk = time(NULL);
           // printf("%s", ctime(&clk));
            //printf("accept failed with error code : %d\n" , WSAGetLastError());
        } else {
            clk = time(NULL);
           // printf("%s", ctime(&clk));
            //puts("Connection accepted.");
        }


        recv_bytes= recv(new_socket , client_reply , 4096 , 0);

        if(recv_bytes == SOCKET_ERROR) {
            clk = time(NULL);
           // printf("\n%s", ctime(&clk));
            //puts("recv failed.\n");
        } else {
            clk = time(NULL);
            //printf("\n%s", ctime(&clk));
            client_reply[recv_bytes] = '\0';
            puts(client_reply);
            printf("%s\n", client_reply);
            puts(inet_ntoa(client.sin_addr));

            s = " ";
            token = strtok(client_reply, s);

            strcpy(user_array[user_index].name, token);

             if( token != NULL ) {

                token = strtok(NULL, s);
             }

         user_array[user_index].port_number = atoi(token);

         user_array[user_index].ip_address = client.sin_addr.s_addr;
        }

    }

    closesocket(s);
    closesocket(new_socket);
}

void discovery_message()
{
    SOCKET s;
    struct sockaddr_in server;
    int c;
    char message[4096];
    int recv_bytes;
    time_t clk;

    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Socket created.\n\n");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = user_array[user_index].ip_address;
    server.sin_port = htons(user_array[user_index].discovery_port_number);
    printf("%s\n", inet_ntoa(server.sin_addr));

    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
        clk = time(NULL);
        //printf("%s", ctime(&clk));
        puts("connect error.");
    } else {
        clk = time(NULL);
        //printf("%s", ctime(&clk));
        puts("Connected!");
    }

    clk = time(NULL);
    //printf("\n%s", ctime(&clk));
    strcpy(message, "Adam 9999");
    message[strlen(message)] = '\0';

    if( send(s , message , strlen(message) , 0) < 0)
    {
        clk = time(NULL);
        //printf("\n%s", ctime(&clk));
        puts("Send failed");
    }

    closesocket(s);
}
