#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Пузырьковая сортировка
	Шейкерная сортировка
*/

int* initArray(const int len) { return (int*) calloc(sizeof(int), len); }

void fillRandom(int* arr, const int len, int border)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
		*(arr + i) = rand() % border;
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void sortBubble(int* arr, const int len)
{
	for (int j = 0; j < len; ++j)
		for (int i = 0; i < len - 1; ++i)
			if (arr[i] > arr [i + 1])
				swap(&arr[i], &arr[i + 1]);
}

void sortShaker(int* arr, const int len)
{
	int left = 1;
	int right = len - 1;
	while (left <= right) {
		int i;
		for (int i = right; i >= left; --i)
			if (arr[i - 1] > arr[i])
				swap(&arr[i], &arr[i - 1]);
		left++;
		for (int i = left; i <= right; ++i)
			if (arr[i - 1] > arr[i])
				swap(&arr[i], &arr[i - 1]);
		right--;
	}
}

void printArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%4d ", *(arr + i));
}

int main(int argc, char const *argv[])
{
	const int SIZE = 100;
	int* arr = initArray(SIZE);
	fillRandom(arr, SIZE, 100);
	printArray(arr, SIZE);

	puts("\n");
	sortBubble(arr, SIZE);
	printArray(arr, SIZE);

	fillRandom(arr, SIZE, 100);
	puts("\n");
	sortShaker(arr, SIZE);
	printArray(arr, SIZE);

	
	return 0;
}