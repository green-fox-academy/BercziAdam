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
    int i;
    for (i = 0; !(dest[i] == '\0'); i++) {
    }
    int j;
    for (j = 0; !(src[j] == '\0'); j++) {
        dest[i + j] = src[j];
    }
    return dest;
}
