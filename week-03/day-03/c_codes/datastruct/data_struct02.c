#include <stdio.h>
int GetSurface();
struct RectangularCuboid {
    double a;
    double b;
    double c;
};

    int GetSurface(struct RectangularCuboid edge){
      int surface= 2*((edge.a*edge.b)+(edge.a*edge.c)+(edge.b*edge.c));
      return surface;
    }

 int GetVolume(struct RectangularCuboid edge){
      int volume= edge.a*edge.b*edge.c;
      return volume;

    }

int main() {
    struct RectangularCuboid edge={2,3,4};
    printf("Surface:%d\n",GetSurface(edge));
    printf("Volume:%d\n",GetVolume(edge));
    return 0;
}
