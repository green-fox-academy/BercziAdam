#include <stdio.h>
#include <stdlib.h>
#define TOTORO 33
// Define the TOTORO macro which holds the number of students in our class

int main()
{

#ifndef TOTORO
#error TOTORO is not defined
#endif

    return 0;
}
