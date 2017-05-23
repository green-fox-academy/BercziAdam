// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys.

// It should print "The party is excellent!" if the the number of girls and
// boys are equal and there are more people coming than 20

// It should print "Quite cool party!"
// if there are more than 20 people coming but the girl - boy ratio is not 1-1

// It should print: "Average party..."
// if there are less people coming than 20

// It should print: "Sausage party"
// if no girls are coming, regardless the count of the people

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int g;
    int b;
    while(1){
    printf("Enter the number of girls first, after that enter the number of boys.\n");
    scanf("%d %d",&g,&b);
    int p = g + b;
    if (g==b && p>=20){
        printf("The party is excellent!\n");
    }else if(p>20 && (b<g||g<b) && !(g==0)){
        printf("Quite cool party!\n");
    }else if(p<20 && !(g==0)){
        printf("Average party...\n");
    }else if(g==0 && b>0){
        printf("Sausage party\n");
    }else if(g==0 && b==0){
        printf("There is nobody in daa house!\n");
    }
    }
    return 0;
}
