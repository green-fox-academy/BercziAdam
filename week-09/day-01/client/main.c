#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <time.h>
#include "socket_functs.h"

//Create a client app that ping the google.com to get than latency, and print it out.

int main(int argc , char *argv[])
{
    struct sockaddr_in server;  //sockaddr_in structure

    WSADATA wsa;    //wsa structure

    SOCKET s;   //socet descriptor structure

    printf("\nInitialising Winsock...\n");

    WSAStartup(MAKEWORD(2,2),&wsa);
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)    //start initialization (version, WSADATA structure's address)
    {
        printf("Failed. Error Code : %d\n",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");


    //creating a socket structure
    //s = socket(AF_INET , SOCK_STREAM , 0 );
    //_In_ int type,(SOCK_STREAM: A socket type that provides sequenced, reliable, two-way, connection-based byte streams with an OOB data transmission mechanism. This socket type uses the Transmission Control Protocol (TCP) for the Internet address family (AF_INET or AF_INET6).)
    //_In_ int af,(AF_INET: The Internet Protocol version 4 (IPv4) address family.)
    //_In_ int protocol(0: service provider will choose the protocol to use or it can be IPPROTO_TCP to set TCP.)
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d\n" , WSAGetLastError());
    }
    printf("Socket created.\n");


    server.sin_addr.s_addr =inet_addr("10.27.6.195"); //localhost
    server.sin_family = AF_INET;   //IPv4
    //char port[20];
    //gets(port);
    //server.sin_port = htons( atoi(port) );
    server.sin_port = htons( 8888 ); //port number which we communicate trough
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }
    puts("Connected!");

    while (1) {

        //send a message to the server
        char message[4096];
        printf("client:\t");
        gets(message);
        message[strlen(message)] = '\0';

        if( send(s , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        char server_reply [4096];
        int recv_bytes = recv(s, server_reply , 4096 , 0);
        if(recv_bytes == SOCKET_ERROR)
        {
            puts("recv failed");
        } else {
            printf("server:\t");
            server_reply[recv_bytes] = '\0';
            puts(server_reply);
        }

    }
    return 0;
}
