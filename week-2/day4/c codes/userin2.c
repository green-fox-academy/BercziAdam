#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char buffer[255];   // Buffer variable for user input
    char catname[255];
     char sentence[255]="";
    //TODO:
    // Get the user's name with gets
    puts("What is your name?");
    gets(buffer);
    //TODO:
        // Print it out with puts
    puts(buffer);
    //TODO:
    // Get the user's pet name with gets
    puts("What is your pet's name?");
    gets(catname);
    //TODO:
    // Print it out
    strcat(sentence,buffer);
    strcat(sentence, "'s cat is called ");
    strcat(sentence, catname);

    puts(sentence);
    return 0;
}
