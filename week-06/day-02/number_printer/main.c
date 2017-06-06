#include <stdio.h>
#include <stdint.h>

void printf_numbers(unsigned long int from, unsigned long int to)
{
	for (unsigned long int i = from; i < to; i++)
		printf("%u\n", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
