#include "func.h"

/*
	Линейный поиск:
		перебор элементов до первого вхождения
	Поиск с барьером (немного быстрее):
		барьер (подменныое совпадение) ставится в конец массива
*/

int searchLinear(int* arr, int len, int value)
{
	int i = 0;
	while (i < len && arr[i] != value)
		i++;

	return (i < len) ? i : -1;
}

int searchBarrier(int* arr, int len, int value) 
{
	int i = 0;
	while (arr[i] != value) ++i;

	return (i < len - 1) ? i : -1;
}

int main(int argc, char const *argv[])
{
	const int SIZE = 40;
	int arr[SIZE];
	fillIntRandom(arr, SIZE, 100);
	printIntArray(arr, SIZE);

	printf("Значение 98 найдено по индексу: %d\n", searchLinear(arr, SIZE, 98));

	arr[SIZE - 1] = 96;
	printf("Значение 96 найдено по индексу: %d\n", searchBarrier(arr, SIZE, 96));

	
	return 0;
}