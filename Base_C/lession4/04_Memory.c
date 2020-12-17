#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int *area = (int*) malloc(123);					// выделение памяти массива в 123 байта
													// и разметить ее типами int - (int*)
	printf("%lu\n", sizeof(int));					// вывести в байтах размер типа int
													// sizeof возвращает long unsigned
	const int SIZE = 10;
	int *array = (int*) malloc(sizeof(int) * SIZE);	// malloc выделяет память без ее очистки
	int *array3 = (int*) calloc(SIZE, sizeof(int));	// calloc выделяет память с ее очисткой
	int array2[SIZE];								// тоже самое 

	int i;
	for (i = 0; i < SIZE; ++i) {					// Вариант 1
		*(array + i) = i * 10;
		printf("%d ", *(array + i));
	}												// Идентичны
	free(array3);				// освобождение оперативной памяти
	puts("");
	for (i = 0; i < SIZE; ++i) {					// Вариант 2
		array2[i] = i * 10;
		printf("%d ", array2[i]);
	}
	puts("");
	const int NEWSIZE = SIZE + 10;
	array = realloc(array, NEWSIZE * sizeof(int));	// расширение (или сужение) выделяемой памяти
	for (i = 0; i < NEWSIZE; ++i) {					// память выделяется в новом месте,
		*(array + i) = i * 10;						// без старых данных
		printf("%d ", *(array + i));
	}
	free(array); 
	return 0;
}