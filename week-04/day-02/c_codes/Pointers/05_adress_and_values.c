#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */


int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';
    int *number_p = &number;
    float *Pi_p = &Pi;
    char *letter_p = &letter;
    printf("%p\t%p\t%p\n%p\t%p\t%p\n", number_p,Pi_p ,letter_p, &number, &Pi, &letter);
    printf("%d\t%f\t%c\n%d\t%f\t%c\n", number, Pi, letter, *number_p, *Pi_p, *letter_p);
    return 0;
}
