#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function which receives a string as parameter, and returns
// the numbers of characters in the string.
// Don't use the strlen() function!
int num_of_char(char *string);
int main()
{
    char str []="but44555";
    printf("%s\n", str);
    printf("%d\n", num_of_char(str));
    return 0;
}

int num_of_char(char *string)
{
    /*
    int i = 0;
    printf("%s",string);
    while (!(string[i] == '\0')) {
            i++;
        if((string[i] == '\0')){
            break;
        }
    }*/
    int i;
    for (i = 0; !(string[i] == '\0'); i++) {
    }
    return i-1;
}
