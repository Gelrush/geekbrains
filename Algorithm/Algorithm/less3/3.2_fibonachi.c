#include <stdio.h>
#include <math.h>

int fib(int n) // экспонинциальная сложность - O(n!)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	return fib(n - 1) + fib(n - 2);
}

void fib2(int* arr, int n) // линейсная сложность - O(n)
{
	if (n > 0)
		fib2(arr, n - 1);
	if (n == 0)
		*(arr + n) = 0;
	if (n == 1)
		*(arr + n) = 1;
	if (n > 1)
		*(arr + n) = *(arr + n - 1) + *(arr + n - 2);
}

void fib3(int n) // математический метод (фомула Бине)
{
	const double f1 = (1 + sqrt(5))/2;
	const double f2 = (1 - sqrt(5))/2;

	int result = (pow(f1, n) - pow(f2, n))/sqrt(5);
	printf("\n%d", result);
}

int main(int argc, char const *argv[])
{
	//-----------------------------
	for (int i = 0; i < 20; ++i)
		printf("%d ", fib(i));
	printf("\n");
	//-----------------------------
	int arr[20];
	fib2(arr, 20);
	for (int i = 0; i < 20; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	//-----------------------------
	fib3(19);

	return 0;
}