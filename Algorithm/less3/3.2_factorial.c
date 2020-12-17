#include <stdio.h>

int recFac(int n)
{
	if (n <= 0)
		return 1;
	return recFac(n - 1) * n;
}

int main(int argc, char const *argv[])
{
	printf("Факториал числа %d = %d\n", 7, recFac(7));
	return 0;
}