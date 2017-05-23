
#include <stdio.h>
#include <stdlib.h>
void function(int i, int n);
int main()
{
    int n = 100;
    int i = 0;
    while (i < n) {
        printf("I won't cheat on the test!\n");
        i++;
    }
    for (i; i < n; i++) {
        printf("I won't cheat on the test!\n");
    }
    do {
        printf("I won't cheat on the test!\n");
        i++;
    } while (i < n);
    function(i, n);
    return 0;
}
void function(int i, int n)
{
    while (i < n) {
        printf("I won't cheat on the test!\n");
        i++;
    }
    for(i; i < n; i++) {
        printf("I won't cheat on the test!\n");
    }
    do {
        printf("I won't cheat on the test!\n");
        i++;
    } while (i < n);
}
