#include <stdio.h>

int main()
{
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};
    int i;
    //TODO:
    // Print out the content of the arrays
    int size = sizeof(int_array) / sizeof(int);
    for (i=0; i < size ;i++) {
            printf("%d ", int_array[i]);
        }
    printf("\n");
    float size1 = sizeof(float_array) / sizeof(float);
    for (i=0; i < size1 ;i++) {
        printf("%f ", float_array[i]);
        }
    return 0;
}
