#include <stdio.h>
#include <stdlib.h>

int gameloop ();
int main()
{
    printf("Hello friend!\nThis is a guessing game, where you have to guess a random generated number.\nPlease give a minimum and a maximum value of the range of the guessing game.\n");
    while (1)
    {
    gameloop();
    printf("Let's begin a New game!:)\n");
    }
    return 0;
}
int gameloop()
{
    srand(time(NULL));
    int Max;
    int Min;
    int guess;

    printf("Enter the maximum value first:",Max);
    scanf("%d",&Max);
    printf("Then enter the minimum value:");
    scanf("%d",&Min);
    printf("Nice, here are some Rules:\n1. You have lives which are proportional to your given range to make your Life easier:)\n2. If you make a wrong guess, i will take 1 life from you, haha...\nLET'S BEGIN THE GAME\n\n");

    int random = rand() % (Max + 1 - Min) + Min;
    int lives = (Max-Min)/25+1;
    if (lives==1)
        {
        printf("I've the number between %d - %d. You have %d life.\nMake your guess.\n", Min, Max, lives);
        }
    else
        {

        printf("I've the number between %d - %d. You have %d lives.\nMake your guess.\n", Min, Max, lives);
        }

    while (lives>0 && Min<guess<Max)
    {

        scanf("%d", &guess);

        if (guess > random)
        {
            lives--;
        printf("Too high. You have %d lives left.\n", lives);
        }
        if (guess < random)
        {
           lives--;
           printf("Too low. You have %d lives left.\n", lives);
        }
        if (guess == random)
        {
        printf("Congratulations. You won!\n");
        }
        if (lives==0)
        {
        printf("Game over! Haha\n");
        }

    }

    return lives;
}
