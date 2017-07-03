#include "main.h"
#include "command_functs_and_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>

void wsa_init()
{
    WSADATA wsa;
    time_t clk;

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
}

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

void print_user_list()
{
    printf("User name \t IP address \t Discovery port number \t Port number\n");
    for(int i = 0; i < user_index; i++)
        printf("%s \t\t %x \t %d \t\t\t %d\n", user_array[user_index].name, user_array[i].ip_address,
                user_array[i].discovery_port_number, user_array[user_index].port_number);
}
