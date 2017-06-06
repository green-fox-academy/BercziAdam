#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a struct called CircularBuffer
// It should store:
// A pointer that points to the start of a dynamically allocated array of ints (could be null) (head pointer)
// A pointer that points to the end of the dynamically allocated array of ints (could be null) (tail pointer)
// A pointer that points to the currently readable buffer item (could be null) (read pointer))
// A pointer that points to the currently writable buffer item (could be null) (write pointer)
// The lenght of the buffer
typedef struct {
    int *head;
    int *tail;
    int *read;
    int *write;
} CircularBuffer;
// TODO:
// Create a function that returns a dynamically allocated CircularBuffer (the buffer itself should be allocated as well, not just the array inside)
// It should take a normal array and it's length as argument, and it should fill all the buffer values from the array
CircularBuffer *CreateCircularBuffer(int *array, int lenght)
{
    int *buffer = (int*) calloc(lenght, sizeof(int));
    CircularBuffer *circbuff = (CircularBuffer*) malloc(sizeof(CircularBuffer));
    memcpy(buffer, array, lenght*sizeof(int));
    circbuff->head = &buffer[0];
    circbuff->read = &buffer[0];
    circbuff->write = &buffer[0];
    circbuff->tail = &buffer[lenght-1];

    return circbuff;
}
// TODO:
// Create a function that resizes a CircularBuffer, it should take a CircularBuffer as a pointer and change that buffers length and reallocate it's array as well. (copying it's values)
void ResizeBuff(CircularBuffer *circbuff, int lenght)
{
    int index_of_write = circbuff->read - circbuff->head;
    int index_of_read = (circbuff->write - circbuff->head);

    circbuff->head = realloc(circbuff->head,lenght*sizeof(int));
    circbuff->tail = &circbuff->head[lenght-1];
    circbuff->read = &circbuff->head[index_of_read];
    circbuff->write = &circbuff->head[index_of_write];
}


// TODO:
// Create a function that takes a CircularBuffer and returns a new CircularBuffer that only contains the even numbers from the old CircularBuffer
CircularBuffer *CreateEvenCircBuff(CircularBuffer *circbuff, int lenght)
{
    int counteven = 0;
    for (int i = 0; i<lenght; i++) {
        if (circbuff->head[i]%2 == 0);
            counteven++;
            printf("%d\n", counteven);
    }
    CircularBuffer *newcircbuff = malloc(sizeof(CircularBuffer));
    newcircbuff->head = (int*) malloc(counteven * sizeof(int));

    int k = 0;
    for (int i = 0; i<lenght; i++) {
        if (circbuff->head[i]%2 == 0 && k < counteven) {
            newcircbuff->head[k] = circbuff->head[i];
            k++;
        }
    }
    newcircbuff->read = &newcircbuff->head[0];
    newcircbuff->write = &newcircbuff->head[0];
    newcircbuff->tail = &newcircbuff->head[counteven-1];

    return newcircbuff;
}
// TODO:
// Try all the functions in the main function, plase deallocate any buffer and the array inside it after using them
int main()
{
    int array1[]= {1, 3, 4, 44, 66, 42, 4};
    int size = sizeof(array1)/sizeof(int);
    CircularBuffer *circbuff = CreateCircularBuffer(array1, size);
    printf("%d\n",*(circbuff->tail));

    ResizeBuff(circbuff, 15);
    printf("%d",*(circbuff->tail));

    CircularBuffer *newcirc = CreateEvenCircBuff(circbuff, size);
    printf("%d\n", *(newcirc->head));
    printf("%d\n", *(newcirc->read));

    free(newcirc->head);
    free(newcirc);
    free(circbuff->head);
    free(circbuff);
    return 0;
}
