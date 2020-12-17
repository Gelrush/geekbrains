#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int ROWS = 10;
	const int COLS = 10;
	int table[ROWS][COLS];						// инициализация массива 1
	for (int i = 0; i < ROWS; i++) 	
		for (int j = 0; j < COLS; j++) 
			table[i][j] = (i + 1) * (j + 1);


	int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}; // инициализация массива 2

	for (int i = 0; i < ROWS; ++i) { 		// вывод массива
		for (int j = 0; j < COLS; ++j) 
			printf("%3d", table[i][j]);
		printf("\n");
	}
	
	char *stringArray[3] = {"Hello", "C-lenguage", "World"}; // массив строк

	for (int i = 0; i < 3; ++i)
		printf("%s\n", *(stringArray + i));

	return 0;
}