#include <stdio.h>
#include <stdlib.h>

int main() {

    int j1 = 10;
	int j2 = 3;
    int j2c=j2*j2*j2;
    int j2s=j2*j2;

   /**< j2s stands for square of j2
        j2c stands for cube of j2  */

	if (j2c>j1>j2s){

      printf("j1 (%d) is greater than square j2 (%d) and smaller than cube j2(%d) ", j1,j2s,j2c);

	}

	else {
        printf("its not true");
	}

	return 0;
}
