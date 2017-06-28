#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <time.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc , char *argv[])
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
