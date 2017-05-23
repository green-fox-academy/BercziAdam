#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pointer = NULL;
    int i;
    // TODO:
    // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
    // Please delete the array before the program exits
    pointer = (int*) calloc(5, sizeof(int));
    for (i = 0; i < 5; i++) {
        pointer[i] = i;
        printf("%d\n", pointer[i]);
    }
    free(pointer);
    return 0;
}
