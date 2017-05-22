#include <stdio.h>
#include <stdint.h>

int main() {

	uint16_t v = 426;
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	v%=4;

	if (v=0){

        printf("Yeah");
	}
else {
        printf("End of program");
	}
	return 0;
}
