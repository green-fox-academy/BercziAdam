#include <stdio.h>
#include <stdint.h>


int main() {
	float w = 24;
	int out = 0;

    w= (int)w%2;


	if (w==0){

        out+= 1;

        printf("%d", out);
	}

	return 0;
}
