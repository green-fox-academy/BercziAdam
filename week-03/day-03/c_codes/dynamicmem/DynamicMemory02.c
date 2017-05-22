#include <stdio.h>
#include <stdlib.h>

int main()
{
    int avr;
    int num_count, i, *count, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &num_count);
    if(num_count==0){
        return;
    }
    count = (int*) calloc(num_count, sizeof(int));
    if(count == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < num_count; ++i)
    {
        scanf("%d", count + i);
        sum += *(count + i);
    }

    avr=sum/num_count;
    printf("Avarage = %d", avr);
    free(*count);
    return 0;
}
