#include <stdio.h>

int euclidus(int a, int b)
{
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("НОД = %d \n", euclidus(a, b));

	return 0;
}