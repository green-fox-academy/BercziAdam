#include <stdio.h>
#include <stdio.h>

/* Write a void function which has two float parameters. The function can do the
totoro operation on those parameters and it also prints out the result of the operation
on the screen.
The totoro operation does the following on two variables (let's say we have "a"
 and "b")
result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979
*/
float TotoroOp ();
int main(){

    TotoroOp ();

    return 0;
}
float TotoroOp ()
{
    float aaa=1;
    float bbb=2;
    float result = aaa*bbb+(aaa+bbb)+aaa*aaa*aaa+bbb*bbb*bbb+3.14159265358979;

    printf("The result is %f", result);

    return ;

}
