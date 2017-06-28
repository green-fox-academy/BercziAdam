#include "command_functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>

#pragma comment(lib,"ws2_32.lib")


typedef struct user {
    char name[256];
    const char *ip_address;
    int port_number;
}user_t;


int main()
{
    startup_com_list();
    char key;
    user_t user_array[50];
    _beginthread(thread_server, 0, NULL);

    while(1) {

        if (kbhit()) {

            key =getch();

            switch(key) {
                case 'h' :
                    print_command_list();
                    break;
                case 'e' :
                    exit(0);
                    break;
                case 'n' :

                    break;
                case 'l' :

                    break;
                case 'd' :
                    break;
                case 'm' :
                    client();
                    break;

            }
        }
    }
    return 0;
}
