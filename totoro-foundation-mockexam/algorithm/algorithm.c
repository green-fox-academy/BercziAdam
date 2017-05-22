/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int getfibonacci(int N);

int main(){
    int N = 15;
    printf("%d", getfibonacci(N));
return 0;
}
int getfibonacci(int N){

    int F[10000];
    int n;

    for( n=0; n<=(N-1); n++ ){
         if (n == 0) {
            F[n]=0;
         } else if (n == 1){
         F[n]=1;
         } else{
        F[n]=F[n-1]+F[n-2];
         }
    }
return F[N-1];
}
