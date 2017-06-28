#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>
/* Server.c */

int main( int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET server_socket;
    struct sockaddr_in server_address, client_address;
    int recv_bytes;
    unsigned int clientLength;
    char message[4096];
    char client_reply[4096];
    time_t clk;
    FILE *server_log;

    server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
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

    if((server_socket = socket(AF_INET , SOCK_DGRAM , 0)) == INVALID_SOCKET) {
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
   //bzero((char*) &server_address, sizeof(server_address));

   /*Fill in server's sockaddr_in*/
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("10.27.6.125");
    server_address.sin_port = htons(1234);

    if( bind(server_socket ,(struct sockaddr *)&server_address , sizeof(server_address)) == SOCKET_ERROR) {
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

    listen(server_socket , 3);

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    puts("Waiting for incoming data...\n");
    fputs("Waiting for incoming data...\n", server_log);

    fclose(server_log);

   while(1) {

        server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
        if (server_log == NULL) {
            printf("\nCannot open file \n\n");
            exit(0);
        }

        clientLength = sizeof(client_address);
        recv_bytes= recvfrom(server_socket, message, 4096, 0, (struct sockaddr*) &client_address, &clientLength);

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
            /*printf("client:\t");
            fprintf(server_log, "client:\t");
            client_reply[recv_bytes] = '\0';
            puts(client_reply);
            fputs(client_reply, server_log);*/
            printf("SERVER: read %d bytes from IP %s(%s)\n", recv_bytes, inet_ntoa(client_address.sin_addr), message);
        }

        /*clk = time(NULL);
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
        }*/

        fclose(server_log);
    }

    closesocket(server_socket);
    WSACleanup();
    fclose(server_log);

    return 0;
}

