#include "command_functs.h"
#include "broadcast.h"
#include "message.h"
#include "discovery_server.h"
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

void thread_server()
{
  while (1) {
    server();
  }
}

void thread_broadcast_server()
{
  while (1) {
    broadcast_server();
  }
}

void thread_discovery_server()
{
  while (1) {
    discovery_server();
  }
}

