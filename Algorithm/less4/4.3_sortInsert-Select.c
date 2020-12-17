#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Сортировка методом вставки (insert):
		рекомендуется использовать в случаях, когда необходимо 
		отсортировать небольшое количество электментов или когда 
		элементы исходной последовательности уже почти отсортированы
	Сортировка методом выбора (selection):
		один из самых медленных алгоритмов, не применяется на практике
*/

int* initArray(const int len) { return (int*) calloc(sizeof(int), len); }

void fillRandom(int* arr, const int len, int border)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
		*(arr + i) = rand() % border;
}

void swapInt(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void printArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%4d ", *(arr + i));
}

void sortInsert(int* arr, const int len)
{
	int temp, pos;
	for (int i = 1; i < len; ++i) {
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

void sortSetection(int* arr, const int len)
{
	int min;
	for (int i = 0; i < len - 1; ++i) {
		min = i;
		for (int j = i + 1; j < len; ++j)
			if (arr[j] < arr[min])
				min = j;
		swapInt(&arr[i], &arr[min]);	
	}
}

int main(int argc, char const *argv[])
{
	const int SIZE = 100;
	int* arr = initArray(SIZE);
	fillRandom(arr, SIZE, 100);
	printArray(arr, SIZE);

	puts("\n");
	sortInsert(arr, SIZE);
	printArray(arr, SIZE);

	fillRandom(arr, SIZE, 100);
	puts("\n");
	sortSetection(arr, SIZE);
	printArray(arr, SIZE);

	
	return 0;
}