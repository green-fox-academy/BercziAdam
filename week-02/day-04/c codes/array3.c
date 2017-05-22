#include <stdio.h>
#include <stdlib.h>

int main() {
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

	//TODO:
    // Print out the content of the arrays
    int i;
    size_t size = sizeof(int_array) / sizeof(int);
    for (i=0; i<size; i++)
    {
        printf("%d\n", int_array[i]);
    }

    size_t size1 = sizeof(float_array) / sizeof(float);
    for (i=0; i<size1; i++)
    {
        printf("%f\n", float_array[i]);
    }


return 0;

}
