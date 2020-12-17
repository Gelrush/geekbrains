#include <stdio.h>
#include <stdlib.h>

/*
	Обмен значениями между двумя колонками/строками двумерного массива
*/

char** initArray(char** array, const int row, const int col)
{
	array = (char**) malloc(sizeof(char*) * row);
	for (int i = 0; i < row; ++i)
		*(array + i) = (char*) calloc(sizeof(char*), col);
	return array;
}

void fillArray(char** array, const int row, const int col, char sym)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(*(array + i) + j) = ++sym;
}

void printArray(char** array, const int row, const int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%4d ", *(*(array + i) + j));
		puts("");
	}
}

void changeRow(char** array, const int row, const int col, int from, int to)
{
	char* temp = *(array + from - 1);
	*(array + from - 1) = *(array + to - 1);
	*(array + to - 1) = temp;
}

void changeCol(char** array, const int row, const int col, int from, int to)
{
	char temp;
	for (int i = 0; i < row; ++i)
	{
		temp = *(*(array + i) + from - 1);
		*(*(array + i) + from - 1) = *(*(array + i) + to - 1);
		*(*(array + i) + to - 1) = temp;
	}
}

int main(int argc, char const *argv[])
{
	const int row = 5;
	const int col = 6;
	char** arr = initArray(arr, row, col);
	fillArray(arr, row, col, 0);
	printArray(arr, row, col);
	
	puts("");
	changeRow(arr, row, col, 2, 3);
	printArray(arr, row, col);

	puts("");
	changeCol(arr, row, col, 2, 3);
	printArray(arr, row, col);


	return 0;
}