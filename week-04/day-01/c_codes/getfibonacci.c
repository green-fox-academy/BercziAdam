#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int get_fibonacci_number(int N);
int main()
{
    int N;
    while (1) {
        printf("Enter which Fibonacci number you would like to get.\n");
        scanf("%d", &N);
        if ((N >= 0)) {
            printf("%d\n", get_fibonacci_number(N));
        } else {
            printf("The entered number is invalid, please enter a number greater-equal 0.\n");
        }
    }
    return 0;
}
int get_fibonacci_number(int N)
{
    int F[10000];
    int n;

    for(n=0 ; n <= (N - 1) ; n++) {
         if (n == 0) {
            F[n] = 0;
         } else if (n == 1){
            F[n] = 1;
         } else{
            F[n] = F[n-1] + F[n-2];
         }
    }
    return F[N - 1];
}
