/*
(необязательно) Написать функцию-обёртку, принимающую 
указатель на область памяти, которую затем можно использовать 
как двумерный массив из элементов типа integer. 
Количество элементов указывается в аргументе функции. 
Массив должен быть гарантированно инициализирован нулями. 
Для проверки - заполните этот массив и выведите на экран.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* reMalloc(int *arr, int number) {
	int column = round(sqrt(number));
	int line = ceil((float) number / (float) column);
	for (int i = 0; i < column; ++i) {
		for (int j = 0; j < line; ++j)
			if (--number >= 0) {
				*(arr + i*line +j) = i + j;
				printf("%d ", *(arr + i*line +j));
			}
		puts("");
	}

	return arr;
}

int main(int argc, char const *argv[])
{
	const int MEMORY = 256;
	const int ELEMENTS = 10;
	int *array = reMalloc(malloc(MEMORY), ELEMENTS);

	return 0;
}