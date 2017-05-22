#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int fibonacci(int fib);

int main(){
int fib = 15;
printf("%d", fibonacci(fib));
return 0;
}
int fibonacci(int fib){

int F[10000];
int n;

for( n=0; n<=(fib-1); n++ ){
     if (n == 0) {
        F[n]=0;
     } else if (n == 1){
     F[n]=1;
     } else{
    F[n]=F[n-1]+F[n-2];
     }
}
return F[fib-1];
}
