#include <stdio.h>
#include <stdlib.h>

int main() {

   int k = 1521;

   int k3;
   int k5;

    k3=k%3;
    k5=k%5;

	if ( (k3==0) | (k5==0) ){

      printf("k is dividable by3 or 5");

	}

	else {
        printf("its not true");
	}

	return 0;
}
