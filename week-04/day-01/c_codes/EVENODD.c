#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    while (1) {
        printf("Enter a number:");
        scanf(" %d", &number);
        if (number % 2 == 0) {
            printf("The number is Even.\n");
        } else {
            printf("The number is Odd.\n");
        }
    }
    return 0;
}
