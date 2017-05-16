#include <stdio.h>
#include <stdint.h>


int main() {

    int a = 654;
	uint64_t b = 654987313;
	// Tell if the reminder of b devided by a is 3
    b%=a;
    printf("%d", b);
	if (b==3){

        printf("the reminder of b devided by a is %d", b);
	}
    else{
        printf("ok");
}
	return 0;
}
