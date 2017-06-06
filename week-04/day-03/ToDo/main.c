#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    int tasknum;
    char *task;
}tasklist_t;
void CommandsList()
{
    FILE *CommandsList = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-04\\day-03\\ToDo\\CommandsList.txt", "r");
    if (CommandsList == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    char c;
    c = fgetc(CommandsList);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(CommandsList);
    }
    fclose(CommandsList);
}
tasklist_t *AddNewTask(tasklist_t *taskarray, char *command, int lenght)
{
       if(taskarra[0]->tasknum != 0) {
        taskarray = realloc (taskarray, taskarray->tasknum++ * sizeof(tasklist_t));
       }
    char *command1 = (char*) calloc (lenght, sizeof(char));
    strcpy(command1, command);

    char *buffer = (char*)calloc(lenght-5, sizeof(char));
    const char quotationmark[2] = {'"'};
    buffer = strtok(command1, quotationmark);
    puts(buffer);
    strcpy(taskarray[taskarray->tasknum].task, buffer);
    //puts(taskarray[taskarray->tasknum].task);

    if (buffer != NULL) {
        buffer = strtok(NULL, quotationmark);
        //strcpy(tlist->task, buffer);
       // puts(tlist->task);
        //printf("%d", tlist->tasknum);
        }
    free(buffer);
    free(command1);
    return taskarray;
}
int main()
{
    CommandsList();

    tasklist_t *taskarray [0]= {0,NULL};

    while (1) {


        char command [100];
        gets(command);
        puts(command);
        int lenght = strlen(command);
    if (command[0] == '-' && command[1] == 'a' && command[2] == ' ' && command[lenght-1] == '"' && command[3] == '"') {
        AddNewTask(taskarray, command, lenght);

    } else if (command[0] == '-' && command[1] == 'l') {



    } else if (command[0] == '-' && command[1] == 'w' && command[2] == 'r') {
    }


    free(taskarray);
    }

    return 0;
}

