#include <stdio.h>


void printArr(int *arr, const int *len) {
	int i = 0;
	while (i < *len)
		printf("%3d,", arr[i++]);

	printf("\n");
}

float average(int *arr, const int *len) {
	float result = 0;
	//printf("%d\n", arr);
	//printf("%d\n", arr + 1);
	//printf("%d\n", arr + 2);
	for (int i = 0; i < *len; ++i)
		result += *(arr + i);			// процесс разыменования, арифметика указателей
		// так как int знаимает 4 байта, с каждой итерацией он прибавляет 4, 8, 12... 
	return result / *len;
}

int main(int argc, char const *argv[])
{
	const int ARRAY_LENGTH = 10;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printArr(arr, &ARRAY_LENGTH);

	printf("Среднее арифметическое: %.2f\n", average(arr, &ARRAY_LENGTH));
	return 0;
}