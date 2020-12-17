/*
	Sublime Text 3
	MinGW
	08.12.2020
*/

#include <stdio.h>
#include <math.h>
#define SUCCESS 0

int isPrime(int n) 
{
	if (n == 0) return 0;
	int last = (int) sqrt(n);
	for (int i = 2; i <= last; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	int num;
	printf("Введите число\n");
	scanf("%d", &num);
	printf("Число %d %s является простым\n", num, (isPrime(num) ? "" : "не"));

	return SUCCESS;
}