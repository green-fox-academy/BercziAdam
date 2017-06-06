#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
struct House {
    char address[100];
    float price;
    int rooms;
    int area;
};
void WorthToBuy(struct House *house, int size);
int main()
{
    struct House house[] = {
        {"Banglades 11.", 16000, 1, 40},
        {"Andrassu 66.", 50000, 2, 100},
        {"Szondi 45.", 30000, 3, 110},
        {"Eotvos 12.", 22000, 2, 85}
};
    int size = sizeof(house)/sizeof(house[0]);
    WorthToBuy(house, size);
    printf("%d", NumberOfHousesWorthToBuy(house, size));
    return 0;
}
void WorthToBuy(struct House *house, int size)
{
    float MarketPrice = 400;
    int i;
    for(i = 0; i<size; i++) {
        if ((house[i].price/(float)house[i].area) <= MarketPrice) {
            printf("House under address %s: Worth to buy!\n", house[i].address);
        } else {
            printf("House under address %s: Doesn't worth to buy!\n", house[i].address);
        }
    }
}
int NumberOfHousesWorthToBuy(struct House *house, int size)
{
    float MarketPrice = 400;
    int i;
    int WorthBuyHouses = 0;
    for(i = 0; i <size; i++) {
            if ((house[i].price/((float)house[i].area)) <= MarketPrice) {
                WorthBuyHouses++;
            } else {
            }
    }
    return WorthBuyHouses;
}
