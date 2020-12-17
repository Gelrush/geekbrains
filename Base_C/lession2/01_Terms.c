// Тернарный оператора if

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 15;
	int c;

	if (a > b) c = a;
	else c = b;
	printf("Большее из чисел - %d\n", c);

	c = 0;
	c = (a > b) ? a : b; // Тернарный оператор
	printf("Большее из чисел - %d\n", c);

	printf("a > b ? %s\n", (a > b) ? "true" : "false"); 

	return 0;
}