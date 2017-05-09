#include <stdio.h>
#include <stdint.h>

int main() {

	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".
    int n=100;

	for (n=1; n<=100; n+=1){

        if (n%3==0 && n%5!=0){
            printf("Fizz\n");
        }
        if (n%5==0 && n%3!=0){
            printf("Buzz\n");
        }
        if (n%(3*5)==0){
            printf("FizzBuzz\n");
        }
        if(n%5!=0 && n%3!=0){
            printf("%d\n", n);
	}
	}
	return 0;
}
