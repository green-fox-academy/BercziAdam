#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */
 enum Transmission {manual, automatic,  CVT, semi_automatic, dual_clutch};
 struct Car{
    char Manufacturers_name[255];
    float Price;
    int Year_of_manufactured;
    enum Transmission Type;
};


int main() {
    struct Car cararray[] = {
    {"Lada", 1000.2, 1972, manual},
    {"Lotus", 200000.34, 2015, automatic},
    {"BMW", 15000.44, 2014, CVT},
    {"Mercedes", 20000.77, 2012, semi_automatic},
    {"Skoda", 3000.456, 2009, dual_clutch},
    };


    get_transmission_count()
    return 0;
}


int get_older_cars_than(struct Car* array, int age){
    int i;
    int size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; i++) {
        if(array[i].Year_of_manufactured>age){

            int array_ptr=array[i].Year_of_manufactured;
            int countold= sizeof(array_ptr);
            return countold;
            }
    }

}


return countold;
}

int get_transmission_count(struct Car* array, enum transmission trnsm){

    int i;
    int size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; i++) {
        switch (array[i].Type){
            case 0 :
                printf("Transmission Type: Manual\n\n");
                break;
            case 1 :
                printf("Transmission Type: Automatic\n\n");
                break;
            case 2 :
                printf("Transmission Type: CVT\n\n");
                break;
            case 3 :
                printf("Transmission Type: semi_automatic\n\n");
                break;
            case 4 :
                printf("Transmission Type: dual_clutch\n\n");
                break;
            default
                printf("Invalid Type of Transmission\n\n");
        }
    }
return counttrans;
}
