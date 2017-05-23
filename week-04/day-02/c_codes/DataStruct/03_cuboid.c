#include <stdio.h>
double GetSurface();

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

int main()
{
    struct rectangular_cuboid edge = {1, 2, 3};
    printf("%f\t%d", GetSurface(edge), GetVolume(edge));
    return 0;
}
double GetSurface(struct rectangular_cuboid edge)
{
   double surface = 2 * ((edge.a * edge.b) + (edge.a * edge.c) + (edge.c * edge.b));
   return surface;
}

int GetVolume(struct rectangular_cuboid edge)
{
   int volume = edge.a * edge.b * edge.c;
   return volume;
}
