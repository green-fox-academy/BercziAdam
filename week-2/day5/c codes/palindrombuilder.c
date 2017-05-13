#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char b[100];
    int i;
    printf("Enter a string.\n");
    gets(b);
    printf("%s",b);
    int n =strlen(b);
    for (i=n-1; i>=0 ;i--)
    {
    printf("%c",b[i]);
    }

    return 0;
}
