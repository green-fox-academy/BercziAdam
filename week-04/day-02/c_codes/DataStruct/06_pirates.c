#include <stdio.h>

struct pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg
float AvarageGold(struct pirate *pirates, int size);
int GoldSum(struct pirate *pirates, int size);
char *RichestWoodenLeg (struct pirate *pirates, int size);
int main()
{
    struct pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };
    int size = sizeof(pirates)/sizeof(pirates[0]);
    printf("%d\n", GoldSum(pirates, size));
    printf("%f\n", AvarageGold(pirates, size));
    printf("%s", RichestWoodenLeg(pirates, size));
    return 0;
}
int GoldSum(struct pirate *pirates, int size)
{
    int i;
    int sum = 0;
    for(i = 0; i< size; i++) {
        sum+=pirates[i].gold_count;
    }
    return sum;
}
float AvarageGold(struct pirate *pirates, int size)
{
    int i;
    int sum = 0;
    for(i = 0; i< size; i++) {
        sum+=pirates[i].gold_count;
    }
    return (double)sum/size;
}
char *RichestWoodenLeg (struct pirate *pirates, int size)
{
    int i;
    int highest_gold_count = 0;
    for (i = 0; pirates[i].gold_count > highest_gold_count && pirates[i].has_wooden_leg == 1; i++) {
         pirates[i].gold_count = highest_gold_count;
    }
    return pirates[i].name;
}
