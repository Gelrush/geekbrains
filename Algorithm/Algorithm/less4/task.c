#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//******************************************************************************
//*							Secondary functions								   *
//******************************************************************************

int** init2dIntArray(int** array, const int row, const int col)
{
	array = (int**) malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i)
		*(array + i) = (int*) calloc(sizeof(int*), col);
	return array;
}

void fill2dIntArray(int** array, const int row, const int col, int border)
{
	srand(time(NULL));
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(*(array + i) + j) = rand() % border;
}

void print2dIntArray(int** array, const int row, const int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%4d ", *(*(array + i) + j));
		puts("");
	}
	puts("");
}

void swapInt(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void printIntArray(double* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%.2f\t", *(arr + i));
	puts("");
}
//******************************************************************************


//------------------------------------------------------------------------------
//------------------------------------Task #1-----------------------------------
//------------------------------------------------------------------------------
void sort2dIntBabble(int** arr, const int row, const int col)
{
	int t_j, t_i;
	for (int c = 0; c < row * col; ++c)
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) {	

				t_i = i;
				t_j = (j + 1 < col) ? j + 1 : 0;
				if (t_j == 0)
					t_i = (i + 1 < row) ? i + 1 : -1;
				if (t_i == -1) continue;
					

				if (arr[i][j] > arr[t_i][t_j])
					swapInt(&arr[i][j], &arr[t_i][t_j]);
			}
}


//------------------------------------------------------------------------------
//------------------------------------Task #2-----------------------------------
//------------------------------------------------------------------------------
void requestArrP(double* arr, const int len)
{
	printf("Введите %d чисел в последовательноть П\n", len);
	for (int i = 0; i < len; ++i) {
		scanf("%lf", &arr[i]);
	}
}

void reverseArrP(double* arr, const int len)
{
	for (int i = 0; i < len / 2; ++i) {
		double temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

void mathArrP(double* arr, const int len)
{
	int res;
	for (int i = 0; i < len; ++i) {
		res = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (res > 400)
			printf("Число %lf с индексом %d превышает верхний предел\n", arr[i], i);
	}
}

int main(int argc, char const *argv[])
{
	//-------------------------------------------
	const int ROW = 10;
	const int COL = 15;
	int** arr = init2dIntArray(arr, ROW, COL);
	fill2dIntArray(arr, ROW, COL, 100);
	print2dIntArray(arr, ROW, COL);
	
	puts("");
	sort2dIntBabble(arr, ROW, COL);
	print2dIntArray(arr, ROW, COL);
	//-------------------------------------------
	const int SIZE = 11;
	double arrP[SIZE];
	requestArrP(arrP, SIZE);
	printIntArray(arrP, SIZE);

	reverseArrP(arrP, SIZE);
	printIntArray(arrP, SIZE);

	mathArrP(arrP, SIZE);

	return 0;
	
}