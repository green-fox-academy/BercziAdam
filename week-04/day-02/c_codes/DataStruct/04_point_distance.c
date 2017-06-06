#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

// TODO:
// Create a function the constructs a Point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
point_t *ConstructPoint(int x, int y);
float Distance (point_t *point, point_t *point1);
int main()
{
    point_t *point = ConstructPoint(3,4);
    point_t *point1 = ConstructPoint(5,6);
    printf("%f", Distance(point, point1));
    free(point);
    free(point1);
    return 0;
}
point_t *ConstructPoint(int x, int y)
{
    point_t *newpoint = (point_t*) malloc(sizeof(point_t));/*a pointer which points to a structure therefor we use -> or(*(newpoint).x) to reach its elements*/
    newpoint->x = x;
    newpoint->y = y;
    return newpoint;
}
float Distance (point_t *point, point_t *point1)
{
    float dist = sqrt(((point->x - point1->x)*(point->x - point1->x))+((point->y - point1->y)*(point->y - point1->y)));
    return dist;
}
