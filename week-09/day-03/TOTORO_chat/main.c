#include "command_functs.h"
#include "broadcast.h"
#include "message.h"
#include "discovery_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock2.h>
#include <time.h>
#include <process.h>


int main()
{
    wsa_init();
    startup_com_list();
    char key;


   // _beginthread(broadcast_server, 0, NULL);
    Sleep(500);

    //_beginthread(server, 0, NULL);
    Sleep(500);

    //_beginthread(discovery_server(), 0, NULL);

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
                print_user_list();
                break;
            case 'd' :
                broadcast_send_message();
                break;
            case 'm' :
                client();
                break;

            }
        }
    }
    return 0;
}
