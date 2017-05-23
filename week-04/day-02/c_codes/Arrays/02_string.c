#include <stdio.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";
    int i;
    //TODO:
    // Print out the two arrays character-by-character
    int size = sizeof(char_array);
    for (i=0; i < size ;i++) {
            printf("%c ", char_array[i]);
        }
    printf("\n");
    int size1 = sizeof(char_array_the_same);
    for (i=0; i < size1 ;i++) {
        printf("%c ", char_array_the_same[i]);
        }
    //TODO:
    // What is the difference between the arrays?
    /**<  the size of the arrays, cause the char_array_the_same[] = "abcd" contains an invisible string terminator (\0), which takes plus 1 byte*/
    return 0;
}
