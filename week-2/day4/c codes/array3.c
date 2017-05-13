#include <stdio.h>
#include <stdlib.h>

int main() {
    int int_array[5] = {1, 654, 987, 654, 31};
    float float_array[5] = {1.2, 3.14, 1.41, 0.707, 1.73};

	//TODO:
    // Print out the content of the arrays
    int i;

    for (i=0; i<5; i++)
    {
        printf("%d\t %f\n", int_array[i], float_array[i]);

}
return 0;

}
