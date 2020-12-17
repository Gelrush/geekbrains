#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARRAY_LENGTH 10 // слова ARRAY_LENGTH заменяются на 50
#define NUMBER_AMOUNT 1000000

int main(int argc, char const *argv[])
{
	int arr[3] = {10, 20, 30};

	int elem = 5;
	float fArr[elem];   // ошибка, нельзя задавать переменное кол. массива

	srand(time(NULL)); // начальное значение для генератора random
	int frequency[ARRAY_LENGTH] = {0}; // нулевые значения в каждой ячейке

			// Вероятность генерации случайных чисел:

	int a;
	for (int i = 0; i < NUMBER_AMOUNT; ++i)  {
		a = rand() % ARRAY_LENGTH;
		frequency[a]++;
	}

	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		printf("Число %2d сгенерированолось %6d (%5.2f%%) раза\n", 
			i+1, frequency[i], ((float)frequency[i] / NUMBER_AMOUNT * 100));
	}
 	
	return 0;
}