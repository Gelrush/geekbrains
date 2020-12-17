#include <stdio.h>

void rec(int a) 
{
	if (a > 0)
		rec(a - 1);
	printf("%5d", a);
}

int sumDigitsRec(int num) 
{
	if (num > 0)
		return num % 10 + sumDigitsRec(num / 10);
	return 0;
}

int main(int argc, char const *argv[])
{
	
	rec(12);

	printf("\nСумма цифр 33559 = %d", sumDigitsRec(33559));
	return 0;
}