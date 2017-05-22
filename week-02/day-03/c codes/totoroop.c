#include<stdio.h>
#include <stdlib.h>

/* Write a void function which has two float parameters. The function can do the
totoro operation on those parameters and it also prints out the result of the operation
on the screen.
The totoro operation does the following on two variables (let's say we have "a"
 and "b")
result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979
*/
void totoroop(float a, float b);

int main() {

    float a = 1;
    float c = 1;

    totoroop(a, c);

    return 0;
}
void totoroop(float a, float b) {

    printf("%f",  a*b+(a+b)+a*a*a+b*b*b+3.14159265358979);
}
