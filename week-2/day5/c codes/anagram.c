#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void anagram();

int main()
{
    if (anagram()==1);
    {
     printf("%c and %c are anagrams", a, b);
    }
    else
    {
       printf("%c and %c are not anagrams", a, b);
    }
return 0;
}
void anagram()
{
    char a[100];b[100];
    int i;
    printf("Enter the first string.\n");
    gets(a);
    printf("Enter the second string.\n");
    gets(b);
    int n =strlen(b);
    for (i=n-1; i>=0 ;i--)
    {
        b[i];
        printf("%c",b[i]);
    }
    if (strcmp(a,b[i]) == 1){
             return 1;
    }
}
