#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int main()
{
    while (1) {
        int x, y;
        int count = 0;
        int guess = 0;
        int rand_max;
        int rand_min;
        printf("New game!\nplease add the minimum number!\n");
        scanf("%d", &rand_min);
        printf("please add the maximum number!\n");
        scanf("%d", &rand_max);
        srand(time(NULL));
        int rand_num = rand_min + rand() % (rand_max + 1 - rand_min);
        y = rand_max - rand_min;
        x = log2(y) / log2(2) - 1;
        if (x <= 0) {
            printf("Please enter a bigger range than 3!\n");

        }


        while (x > count && x > 0) {
            printf("I have a number between %d and %d. You have %d lives\n", rand_min, rand_max, x);
            printf("Please make a guess!\n");
            scanf("%d", &guess);
            count++;
            if (guess == rand_num) {
                printf("Yeeeeey, you did well! It took you %d tires!", count);
                break;
            }
            else if (guess > rand_num)
                printf("Too big, You have %d, lives left\n", x - count);
            else if (guess < rand_num)
                printf("Too low, You have %d, lives left\n", x - count);

        }
        if (count = x)
            printf("You have used all your lives!\n");
    }
	return 0;
}
