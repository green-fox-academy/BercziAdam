#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkanagram();
int main()
{
   char anagram[], margana[];
   int ana;

   printf("Enter first word\n");
   gets(anagram);

   printf("Enter second word\n");
   gets(margana);

   flag = check_anagram(a, b);

   if (flag == 1)
      printf("\"%s\" and \"%s\" are anagrams.\n", anagram, margana);
   else
      printf("\"%s\" and \"%s\" are not anagrams.\n", anagram, margana);


    return 0;
}
int checkanagram()
{   char anagram [];
    int i;

    for (i=0; i<strlen(anagram); i++ )
    {
        anagram[i]=i;

    }
    char margana[];
    for(i=strlen(margana); i>0; i--)
    {
       margana [i]=i;
    }


}
