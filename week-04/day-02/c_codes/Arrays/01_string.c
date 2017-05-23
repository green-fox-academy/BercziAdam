#include <stdio.h>

int main()
{
    char my_name_array[] = "My Name";
    int i;
    //TODO:
    // Print out the array character-by-character
    int size = sizeof(my_name_array);
    for (i=0; i < size ;i++) {
        printf("%c ", my_name_array[i]);
    }
    return 0;
}
