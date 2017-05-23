/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int currentyear = 2017;
    int birthyear;
    int oldage = 100;
    char name[20];

    printf("Enter your name.\n");
    scanf("%s", name);
    printf("Enter your birthyear:\n");
    scanf("%d", &birthyear);
    int yearsleft = oldage - (currentyear - birthyear);
    printf("%s will be %d years old in %d years.", name, oldage, yearsleft);
    return 0;
}
