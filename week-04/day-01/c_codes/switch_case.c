/*
Write a program which receives a number between 0-10 from the user.
It prints out the english word for that number on the screen.
For example if the user enters 8, the program prints out "Eight".
Use switch-case in this task!
Handle the invalid user input!
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while (1) {
        printf("Enter a number between 0 and 10,\n");
        scanf("%d", &n);
        switch (n) {
                case 0 :
                    printf("Zero\n");
                    break;
                case 1 :
                    printf("One\n");
                    break;
                case 2 :
                    printf("Two\n");
                    break;
                case 3 :
                    printf("Three\n");
                    break;
                case 4 :
                    printf("Four\n");
                    break;
                case 5 :
                    printf("Five\n");
                    break;
                case 6 :
                    printf("Six\n");
                    break;
                case 7 :
                    printf("Seven\n");
                    break;
                case 8 :
                    printf("Eight\n");
                    break;
                case 9 :
                    printf("Nine\n");
                    break;
                case 10 :
                    printf("Ten\n");
                    break;
                default :
                    printf("Invalid number\n");
                }
    }
    return 0;
}
