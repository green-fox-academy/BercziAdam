#include "command_functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>
#include <windows.h>

#pragma comment(lib,"ws2_32.lib")


void startup_com_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\commandlist.txt", "r");
    if(commandlist == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    char c;
    c = fgetc(commandlist);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(commandlist);
    }
    fclose(commandlist);
    printf("\n\n");
}

void print_command_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\commandlist.txt", "r");
    if(commandlist == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    char c;
    c = fgetc(commandlist);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(commandlist);
    }
    fclose(commandlist);
    printf("\n\n");
}

void client()
{
    struct sockaddr_in server;
    WSADATA wsa;
    SOCKET s;
    time_t clk;
    char hostname[256];
    char ip[20];
    struct hostent *he;
    struct in_addr **addr_list;
    char port[6];
    int i;
    int recv_bytes;
    char message[4096];
    char server_reply [4096];
    FILE *client_log;

    client_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-02\\client\\bin\\Release\\client_log.txt", "a+");
    if (client_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(client_log, "\n%s", ctime(&clk));
    printf("Initialising Winsock...\n\n");
    fprintf(client_log, "Initialising Winsock...\n\n");

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

    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET) {
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

    printf("Please enter the hostname.\n");
    fprintf(client_log, "Please enter the hostname.\n");
    gets(hostname);
    fprintf(client_log, "%s\n",hostname);
    hostname[strlen(hostname)] = '\0';

    if ( (he = gethostbyname( hostname ) ) == NULL) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(client_log, "\n%s", ctime(&clk));
        printf("gethostbyname failed : %d\n\n" , WSAGetLastError());
        fprintf(client_log, "gethostbyname failed : %d\n\n" , WSAGetLastError());
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
    }

    clk = time(NULL);
    printf("\n%s", ctime(&clk));
    fprintf(client_log, "\n%s", ctime(&clk));
    printf("%s resolved to : %s\n\n" , hostname , ip);
    fprintf(client_log, "%s resolved to : %s\n\n" , hostname , ip);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    printf("Please enter a port number.\n");
    fprintf(client_log, "Please enter a port number.\n");
    gets(port);
    fprintf(client_log, "%s\n", port);

    server.sin_port = htons(atoi(port));

    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "\n%s", ctime(&clk));
        puts("connect error.");
        fputs("connect error.", client_log);
        return 1;
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "\n%s", ctime(&clk));
        puts("Connected!");
        fputs("Connected!", client_log);
    }

    fclose(client_log);

    while (1) {

        client_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-02\\client\\bin\\Release\\client_log.txt", "a+");
        if (client_log == NULL) {
            printf("Cannot open file \n\n");
            fprintf(client_log, "Cannot open file \n\n");
            exit(0);
        }

        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(client_log, "\n%s", ctime(&clk));
        printf("client:\t");
        fprintf(client_log, "client:\t");
        gets(message);
        fprintf(client_log, "%s", message);
        message[strlen(message)] = '\0';

        if( send(s , message , strlen(message) , 0) < 0)
        {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(client_log, "\n\n%s", ctime(&clk));
            puts("Send failed");
            fputs("Send failed", client_log);
            return 1;
        }

        recv_bytes = recv(s, server_reply , 4096 , 0);

        if(recv_bytes == SOCKET_ERROR) {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(client_log, "\n%s", ctime(&clk));
            puts("recv failed");
            fputs("recv failed", client_log);
        } else {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(client_log, "\n%s", ctime(&clk));
            printf("server:\t");
            fprintf(client_log, "server:\t");
            server_reply[recv_bytes] = '\0';
            puts(server_reply);
        }

        fclose(client_log);
    }

    closesocket(s);
    WSACleanup();
    fclose(client_log);

    return 0;
}

void server()
{
        WSADATA wsa;
    SOCKET s;
    SOCKET new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int c;
    char message[4096];
    char client_reply[4096];
    int recv_bytes;
    time_t clk;
    char hostname[256];
    char ip[20];
    struct hostent *he;
    struct in_addr **addr_list;
    char port[6];
    int i;
    FILE *server_log;

    server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-02\\server\\bin\\Release\\server_log.txt", "a+");
    if (server_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    printf("Initialising Winsock...\n\n");
    fprintf(server_log, "Initialising Winsock...\n\n");

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
        fprintf(server_log, "Failed. Error Code : %d\n\n",WSAGetLastError());
        return 1;
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Initialised.\n\n");
        fprintf(server_log, "Initialised.\n\n");
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

    printf("Please enter the hostname.\n");
    fprintf(server_log, "Please enter the hostname.\n");
    gets(hostname);
    fprintf(server_log, "%s\n",hostname);
    hostname[strlen(hostname)] = '\0';

    if ( (he = gethostbyname( hostname ) ) == NULL) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        printf("gethostbyname failed : %d\n\n" , WSAGetLastError());
        fprintf(server_log, "gethostbyname failed : %d\n\n" , WSAGetLastError());
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
    }

    clk = time(NULL);
    printf("\n%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    printf("%s resolved to : %s\n\n" , hostname , ip);
    fprintf(server_log, "%s resolved to : %s\n\n" , hostname , ip);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    printf("Please enter a port number.\n");
    fprintf(server_log, "Please enter a port number.\n");
    gets(port);
    fprintf(server_log, "%s\n", port);

    server.sin_port = htons(atoi(port));

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

    listen(s , 3);

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

        server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-02\\server\\bin\\Release\\server_log.txt", "a+");
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

    return 0;
}

void thread_server()
{
  while (1) {
    server();
  }
}
