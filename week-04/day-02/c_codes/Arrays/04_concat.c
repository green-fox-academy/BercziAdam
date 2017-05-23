#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
char *strcat1(char *dest,const char *src);
int main()
{
    char string1[100];
    char string2[50];
    scanf("%s %s", string1, string2);
    printf("%s", strcat1(string1, string2));
    return 0;
}
char *strcat1(char *dest, const char *src)
{
    strcat(dest, src);
    return dest;
}
