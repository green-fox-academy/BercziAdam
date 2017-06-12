#include "temp_logger_functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rs232.h"
#include <conio.h>

int index;
void print_command_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-06\\day-04\\temp_logger\\commandlist.txt", "r");
    if (commandlist == NULL) {
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

void startup_com_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-06\\day-04\\temp_logger\\commandlist.txt", "r");
    if (commandlist == NULL) {
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

void list_available_ports()
{
    printf("The number of available ports:%d\n", comEnumerate());
    for (int i = 0; i < comEnumerate(); i++)
    printf("The port's name is %s\n", comGetPortName(i));
    //int length = strlen(comGetInternalName(0));
    //for (int i = 0;i <length; i++)
    //printf("%c\t%d\n", comGetInternalName(0)[i]);
}

int set_port_name()
{

    char portname[10];
    printf("Please select a port!\n");
    gets(portname);
    int i = 0;
    for (i; i < comEnumerate(); i++) {
        if (strstr(strupr(portname), comGetPortName(i))) {
            index = i;
            printf("%s\t%d\n", comGetPortName(i),index);

        } else
            printf("Please enter a valid COM port!");
    }
    return i;
}

void set_file_write()
{
    printf("Please enter a file name, which will be used as a log file(*.txt)!");
    char text_file_name[20];
    gets(text_file_name);

    char buf[24];
    snprintf(buf, sizeof(buf), "%s.txt", text_file_name);

    FILE *fptr = fopen(buf, "a");
    if(fptr == NULL) {

      printf("Error!");
      exit(1);
    }

    /*printf("Enter a sentence:\n");
    gets(sentence);

    fprintf(fptr,"%s", sentence);*/
    fclose(fptr);
}

void open_selected_port()
{
    printf("%d\n",comOpen(index, 115200));
}

void start_and_stop_logging(char *buffer_array)
{
    char buffer;
    int i = 0;
   // printf("%d\t%c",comRead(index, &buffer, 1), &buffer);
    /*while (buffer != '\n') {
		// Check if there is enough space in the buffer
		if (i < (100 - 1)) {
			// Check if we are not near the end of the line (cr character)
			if (buffer != '\r') {
				buffer_array[i] = buffer;
				i++;
			}
		}
		while (comRead(index, &buffer, 1) == 0);
	}
	// Put terminating zero at the end
	buffer_array[i] = '\0';*/
    while (i < 100) {
        while (comRead(index, &buffer, 1) == 1) {
            printf("%c", buffer);
            if (i == 14)
                printf("It is freaking hot\n");
            if (i == 26)
                printf("its getting warmer...\n");
            if (i == 38
                )
                printf("Go to the beach NOOOW biiiitch\n");
            if (i> 40)
                printf("And drink beer!\n");
            i++;
        }
    }
}
