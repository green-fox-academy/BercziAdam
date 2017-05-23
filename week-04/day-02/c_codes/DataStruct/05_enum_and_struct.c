#include <stdio.h>

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
    enum car_type type;
    double km;
    double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main()
{
    struct Car car1 = {VOLVO, 12333.5, 66.33};
    struct Car car2 = {TOYOTA, 123.5, 46.23};
    struct Car car3 = {LAND_ROVER, 123633.5, 34.67};
    struct Car car4 = {TESLA, 1233.5, 0};

    PrintCar(car3);
    return 0;
}
void PrintCar (struct Car car)
{
    if(car.type == TESLA) {
        printf("%d\t%f\n",car.type, car.km);
    } else {
        printf("%d\t%f\t%f\n",car.type, car.km, car.gas);
    }
}
