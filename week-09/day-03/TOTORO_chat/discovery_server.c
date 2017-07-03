#include "command_functs.h"
#include "discovery_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>
#include <windows.h>

#pragma comment(lib,"ws2_32.lib")

void discovery_server()
{
    SOCKET s;
    SOCKET new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char message[4096];
    char client_reply[4096];
    int recv_bytes;
    time_t clk;
    FILE *server_log;

    server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\discovery_server_log.txt", "a+");
    if (server_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
        fprintf(server_log, "Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Socket created.\n\n");
        fprintf(server_log, "Socket created.\n\n");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(15000);

    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        printf("Bind failed with error code : %d\n\n" , WSAGetLastError());
        fprintf(server_log, "Bind failed with error code : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        puts("Bind done.\n");
        fputs("Bind done.\n", server_log);
    }

    listen(s , 50);

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    puts("Waiting for incoming connections...\n");
    fputs("Waiting for incoming connections...\n", server_log);

    c = sizeof(struct sockaddr_in);

    new_socket = accept(s, (struct sockaddr *)&client, &c);

    if (new_socket == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        printf("accept failed with error code : %d\n" , WSAGetLastError());
        fprintf(server_log, "accept failed with error code : %d\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        puts("Connection accepted.");
        fputs("Connection accepted.", server_log);
    }

    fclose(server_log);

    while(1) {

        server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\discovery_server_log.txt", "a+");
        if (server_log == NULL) {
            printf("Cannot open file \n\n");
            exit(0);
        }

        recv_bytes= recv(new_socket , client_reply , 4096 , 0);

        if(recv_bytes == SOCKET_ERROR) {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(server_log, "\n%s", ctime(&clk));
            puts("recv failed.\n");
            fputs("recv failed.\n", server_log);
        } else {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(server_log, "\n\n%s", ctime(&clk));
            printf("client:\t");
            fprintf(server_log, "client:\t");
            client_reply[recv_bytes] = '\0';
            puts(client_reply);
            fputs(client_reply, server_log);
        }

        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n\n%s", ctime(&clk));
        printf("server:\t");
        fprintf(server_log, "server:\t");
        gets(message);
        fprintf(server_log, "%s", message);
        message[strlen(message)] = '\0';

        if( send(new_socket , message , strlen(message) , 0) < 0) {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            puts("Send failed.\n\n");
            fprintf(server_log, "\n%s", ctime(&clk));
            fputs("Send failed\n\n", server_log);
        }

        fclose(server_log);
    }

    closesocket(s);
    closesocket(new_socket);
    WSACleanup();
    fclose(server_log);
}
