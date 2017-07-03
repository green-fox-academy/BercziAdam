#include "main.h"
#include "message.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>
int i;
void send_message()
{
    struct sockaddr_in server;
    SOCKET s;
    time_t clk;
    char message[4096];
    char server_reply [4096];
    char user_name[256];

    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Socket created.\n\n");
    }

    gets(user_name);

    for(i = 0; i <= user_index; i++) {
        if(strcmp(user_name, user_array[i].name) == 1) {
                printf("%d", i);
            break;
        }
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = (user_array[i].ip_address);
    server.sin_port = htons(user_array[i].port_number);

    while (1) {

        if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
            clk = time(NULL);
            printf("%s", ctime(&clk));
            puts("connect error client message.");
        } else {
            clk = time(NULL);
            printf("%s", ctime(&clk));
            puts("Connected!");
        }

        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        printf("client:\t");
        gets(message);
        message[strlen(message)] = '\0';

        if( send(s , message , strlen(message) , 0) < 0)
        {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            puts("Send failed");
        }

    }
    closesocket(s);
}

void message_server()
{
    SOCKET s;
    SOCKET new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char client_reply[4096];
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
    server.sin_port = htons(9999);

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
        puts("Waiting for incoming connections...\n");

        c = sizeof(struct sockaddr_in);

        new_socket = accept(s, (struct sockaddr *)&client, &c);

        if (new_socket == INVALID_SOCKET) {
            clk = time(NULL);
           // printf("%s", ctime(&clk));
            printf("accept failed with error code : %d\n" , WSAGetLastError());
        } else {
            clk = time(NULL);
           // printf("%s", ctime(&clk));
            puts("Connection accepted.");
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
            printf("%s\n",client_reply);
            puts(inet_ntoa(client.sin_addr));

        }

    }

    closesocket(s);
    closesocket(new_socket);
}
