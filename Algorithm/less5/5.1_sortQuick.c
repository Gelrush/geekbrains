#include "func.h"

/*
	Сортировка Хоара (очень быстрая):
		рекурсивная сортировка, замена значений с противоположных сторон
		и уход в 2 рекурсии от остановившихся элементов до начала/конца массива
	Сортировка Ломуто:
		рекурсивная, последовательно элементы сравнивается с последним, 
		если меньше, то меняется с счетчиком и увеличивает его 
		(счетчик устанавливается на первый элемент), далее уход в 2 рекурсии 
		от начала до счетчика и от счетчика до конца
*/

void qs(int* arr, int first, int last)
{
	int i = first;
	int j = last;

	int x = arr[(first + last) / 2];

	do { 	// разбиение Хоара - сравнение 2х элементов с разных сторон
			// с каким то любым элементом массива и замена значей если 
			// один больше другого, пока они не встретятся  
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			swapInt(&arr[i], &arr[j]);
			i++; 
			j--;
		}
	} while (i <= j);

	if (i < last) qs(arr, i, last);
	if (first < j) qs(arr, first, j);
}

void qsL(int* arr, int first, int last)
{
	if (first < last) {
		int x = arr[last];
		int i = first;
		int j;
		for (j = first; j <= last - 1; j++)
			if (arr[j] <= x) {
				swapInt(&arr[i], &arr[j]);
				i++;
			}
		swapInt(&arr[i], &arr[last]);		
		qsL(arr, first, i - 1);
		qsL(arr, i + 1, last);
	}
}

int main(int argc, char const *argv[])
{
	const int SIZE = 30;
	int arr[SIZE];
	fillIntRandom(arr, SIZE, 100);	
	printIntArray(arr, SIZE);	

	qs(arr, 0, SIZE - 1);
	printIntArray(arr, SIZE);

	fillIntRandom(arr, SIZE, 100);
	qsL(arr, 0, SIZE - 1);
	printIntArray(arr, SIZE);
	
	
	return 0;
}