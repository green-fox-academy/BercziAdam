#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
     int numbers[] = {5, 6, 7, 8, 9};
    int* number_pointer = &numbers;
    //TODO:
    // The "number_pointer" should point to the third element of the array called "numbers",
    // than please print its value with it. Solve the problem without reusiong the "&" operator
    // for geting the address of the third element.
    printf("%p\n", &number_pointer[2]);
    printf("%d", *(number_pointer+2));
    return 0;
}
