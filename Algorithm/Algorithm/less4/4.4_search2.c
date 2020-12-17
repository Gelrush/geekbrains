#include "func.h"

/*
	Бинарный поиск:
		только для отсортированного массива
		последовательное деление на 2 части
	Интерполяционный поиск:
		предсказание индекса значения с помощью формулы
		далее так же деление массива на 2 части

*/

int searchBinary(int* arr, const int len, int value)
{
	int l = 0;
	int r = len - 1;
	int mid = (l + r) / 2;
	
	while (l < mid && arr[mid] != value) {
		if (arr[mid] <= value)
			l = mid;
		else r = mid;
		mid = (l + r) / 2;
	}
	return (arr[mid] == value) ? mid : -1;
}

int searchInter(int* arr, const int len, int value)
{
	int mid;
	int l = 0;
	int r = len - 1;

	while (arr[l] < value && arr[r] > value) {
		mid = l + ((value - arr[l]) * (r - l)) / (arr[r] - arr[l]);
		if (arr[mid] < value)
			l = mid + 1;
		else if (arr[mid] > value)
			r = mid - 1;
		else return mid;
	}

	if (arr[l] == value)
		return l;
	if (arr[r] == value)
		return r;
	return -1;
}


int main(int argc, char const *argv[])
{
	const int SIZE = 41;
	int arr[SIZE];
	fillIntRandom(arr, SIZE, 100);	
	sortIntShaker(arr, SIZE);
	printIntArray(arr, SIZE);	

	printf("Значение 77 имеет индекс: %d\n", searchBinary(arr, SIZE, 77));
	printf("Значение 8 имеет индекс: %d\n", searchInter(arr, SIZE, 8));	
	
	return 0;
}