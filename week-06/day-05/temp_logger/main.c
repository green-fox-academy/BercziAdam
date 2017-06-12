#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "temp_logger_functs.h"
#include "rs232.h"
#include <time.h>

int main()
{
    startup_com_list();
    while (1) {

    char command[1];
    gets(command);
    printf("\n\n");

    char buffer_array[100];

    if (command[0] == 'h')
        print_command_list();
    else if (command[0] == 'e')
        return 0;
    else if (command[0] == 'l')
        list_available_ports();
    else if (command[0] == 'p')
        set_port_name();
    else if (command[0] == 'w')
        set_file_write();
    else if (command[0] == 'o')
        open_selected_port();
    else if (command[0] == 's')
        start_and_stop_logging(buffer_array);
    else
        printf("Invalid command, please enter a new one!");
    }
    return 0;
}
