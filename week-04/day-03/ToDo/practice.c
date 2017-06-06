#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Taskadd{
    int number;
    char newtask[50];
}AddNewTask;
int main()
{
    char command[100];
    gets(command);
    int lenght = sizeof(command);
    //puts(buffer);
    //AddNewTask *taskadd = (AddNewTask*) malloc(100*sizeof(AddNewTask));

    AddNewTask taskadd []= {
        {1, "fing"},
        {2, "kaka"},
        {3, "fos"},
    };


    /*printf("%d\t%s", taskadd[1].number, taskadd[1].newtask);
    taskadd[1].number = 5;
    strcpy(taskadd[1].newtask, "fasz");
    printf("%d\t%s", taskadd[1].number, taskadd[1].newtask);
    AddNewTask *taskadd1 = (AddNewTask*) malloc(3 * sizeof(AddNewTask));
    strcpy(taskadd1[0].newtask, command);
    taskadd1[0].number = 10;
    printf("%d\t%s", taskadd1[0].number, taskadd1[0].newtask);*/

    AddNewTask *taskadd1 = (AddNewTask*) malloc(3 * sizeof(AddNewTask));
    char *command1 = (char*) calloc (lenght, sizeof(char));
    strcpy(command1, command);

    char *buffer = (char*)calloc(lenght-5, sizeof(char));
    const char quotationmark[2] = {'"'};
    buffer = strtok(command1, quotationmark);
    puts(buffer);
    strcpy(taskadd1[1].newtask, buffer);
    //puts(taskadd1[1].newtask);
    if (buffer != NULL){
    buffer = strtok(NULL, quotationmark);
    char *buffer1 = (char*)calloc(lenght-5, sizeof(char));
    buffer1 = buffer;
    strcpy(taskadd1[1].newtask, buffer1);
    puts(buffer1);
    }
   // strcpy(taskadd1[1].newtask, buffer);
    //puts(taskadd1[1].newtask);
    free(taskadd1[1].newtask);

    free(command1);
return 0;
}
