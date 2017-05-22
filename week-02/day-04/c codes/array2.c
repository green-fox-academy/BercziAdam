#include <stdio.h>
#include <stdlib.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";
    int i;
	//TODO:
    // Print out the two arrays character-by-character
   for (i=0; i<sizeof(char_array); i++)
    {
        printf("%c\t %c\n", char_array[i],char_array_the_same[i]);
    }
	//TODO:
    // Print out the array character-by-character
    for (i=0; i<sizeof(char_array_the_same); i++)
    {
        printf("%c\t %c\n", char_array[i],char_array_the_same[i]);

	//TODO:
    // What is the difference between the arrays?
    /**<  the size of the arrays, cause the char_array_the_same[] = "abcd" contains an unvisible string terminator (\0), which takes plus 1 byte*/
    }

    return 0;
}
