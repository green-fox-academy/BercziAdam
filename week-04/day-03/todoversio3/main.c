#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    int tasknum;
    char task[100];
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
void *AddNewTask(tasklist_t *tlist, char *command, int lenght, int *count_a)
{

    if (command[0] == '-' && command[1] == 'a' && command[2] == ' ' && command[lenght-1] == '"' && command[3] == '"') {
        /*if (tlist == NULL) {
        tlist = (tasklist_t*) malloc(sizeof(tasklist_t));

        } else {
            tlist = (tasklist_t*) realloc(tlist, *count_a * sizeof(tasklist_t));
        }
            printf("%p\t%d\n", tlist, sizeof(tlist));*/
        char *command1 = (char*) calloc (lenght, sizeof(char));
        strcpy(command1, command);

        char *buffer = (char*)calloc(lenght-5, sizeof(char));
        const char quotationmark[2] = {'"'};
        buffer = strtok(command1, quotationmark);

        if (buffer != NULL) {
            buffer = strtok(NULL, quotationmark);
            }
        strcpy(tlist[*count_a].task, buffer);
        tlist[*count_a].tasknum = *count_a + 1;
        printf("%d\t%d\t%s\n", (*count_a)++,tlist[*count_a].tasknum, tlist[*count_a].task);
        free(command1);
        free(buffer);
    }

}
void PrintTasks (tasklist_t *tlist, int count_a)
{
    for (int i = 0; i < count_a; i++) {
        printf("%d\t%d\t%s\n",count_a, tlist[i].tasknum, tlist[i].task);
    }
}
int main()
{
    CommandsList();

    //tasklist_t *tlist []= {0,"NULL"};
    int count_a = 0;
    //printf("%p\t%d\n", tlist, sizeof(tlist));

    tasklist_t *tlist = (tasklist_t*) malloc(1 * sizeof(tasklist_t));

    printf("%p\t%d\n", tlist, sizeof(tlist));
    while (1) {
        char command [100];
        gets(command);
        int lenght = strlen(command);

        AddNewTask(tlist, command, lenght, &count_a);

    }

    free(tlist);
    return 0;
}

