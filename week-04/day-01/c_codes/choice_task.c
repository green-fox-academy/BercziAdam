//make it work

int main()
{
    printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
    int number = rand() % 500;
    int pressedN;
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n");
    while (1) {
        scanf("%d", &pressedN);
        if (pressedN == 1) {
            printf("%p\n", &number);
        } else if (pressedN == 2) {
            printf("%d\n", number);
        } else if (pressedN == 3) {
            printf("%d\n", number*=2);
        }
    }
return 0;
}
