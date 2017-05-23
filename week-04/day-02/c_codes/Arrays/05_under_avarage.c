#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.
double avarage(double *array, double length);
double avarage(double *array, double length)
{
    int i;
    double sum = 0;
    double avr;
    for(i = 0; i <length; i++) {
        sum += array[i];
    }
    return avr = sum / length;
}
// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.

int main()
{
    double array1[] = {1.33, 1.54656, 4, 545};
    double size = sizeof(array1)/sizeof(double);
    printf("%f", avarage(array1, size));
    return 0;
}
