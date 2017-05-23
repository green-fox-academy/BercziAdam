#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main()
{
    int *count = NULL;
    int number_count_times, i, sum = 0;
    float avr;
    printf("Please enter the number count times.\n");
    scanf("%d", &number_count_times);
    count =  (int*) calloc(number_count_times, sizeof(int));
    printf("Please enter the counts number count times.\n");
    for(i = 0; i < number_count_times; i++){
        scanf("%d", &count[i]);
        sum+=count[i];
    }
    avr = (float)sum / number_count_times;
    printf("%f", avr);
    free(count);
    return 0;
}
