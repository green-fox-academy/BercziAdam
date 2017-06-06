#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void  palindrome(char *input);

int main()
{
	char input[100];
	printf("please enter a word: \n");
	scanf("%s", input);
	palindrome(input);
	return 0;
}

void  palindrome(char *input)
{
	printf("%s", input);
	char pointer[strlen(input)];
	int i;
	for (i = 0; i < strlen(input); i++) {
		pointer[i] = input[strlen(input) - 1 - i];
		printf("%c", pointer[i]);
	}
}
