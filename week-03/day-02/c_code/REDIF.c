#include <stdio.h>
#include <stdlib.h>


#define TOTORO
int main()
{


    #undef  TOTORO
    #define TOTORO 42

    printf("Totoro class member count:\t%d", TOTORO);


    return 0;
}
