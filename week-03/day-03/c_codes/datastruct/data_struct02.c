#include <stdio.h>
int GetSurface();
struct RectangularCuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
    int GetSurface(struct RectangularCuboid edge){
      edge.a;
      edge.b;
      edge.c;
      int surface= 2*((edge.a*edge.b)+(edge.a*edge.c)+(edge.b*edge.c));
      return surface;
    }


// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
 int GetVolume(struct RectangularCuboid edge){
      edge.a;
      edge.b;
      edge.c;
      int volume= edge.a*edge.b*edge.c;
      return volume;

    }

int main() {
    struct RectangularCuboid edge={2,3,4};
    printf("Surface:%d\n",GetSurface(edge));
    printf("Volume:%d\n",GetVolume(edge));
    return 0;
}
