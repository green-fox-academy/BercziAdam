typedef struct{
    int number;
    char *newtask;
}tlist_t;


int main()
{
    tlist_t * tasklist = (tlist_t*)malloc (sizeof(tlist_t));
    char command [100];
    gets(command);
    int length = strlen(command);

    //puts(command);
    tasklist->number = 0;
    tasklist->newtask = '\0';
    printf("%d\t%s", tasklist->number, tasklist->newtask);

    free(tasklist);
return 0;
}
tlist_t *Newtask(tlist_t *tasklist, char *command,int length)
{

    tasklist = realloc (tasklist, tasklist->number++ * sizeof(tlist_t));

    const char quotationmark[2] = {'"'};

    char *command1 = (char*) calloc ( length, sizeof(char));
    strcpy(command1, command);
    puts(command1);
    char *buffer = (char*)malloc(100 * sizeof(char));
    buffer = strtok(command1, quotationmark);
    //puts(buffer);
    //strcpy(tlist[].task, buffer);
    //puts(tlist[0].task);

    /*if (buffer != NULL) {
        buffer = strtok(NULL, quotationmark);
        strcpy(tlist[count_a].task, buffer);
        puts(tlist[count_a].task);
        printf("%d", count_a);
        }
    free(buffer);
    free(command1);*/

        return tasklist;
}
