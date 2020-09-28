/*
Task #2 - Cycle
by D. Frolov
on Sublime + gcc
27.09.2020
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
				//  Task 1:
	/*
	int x;

	do {
	printf("Введите целое число: ");
	fseek(stdin, 0, SEEK_END);				// очищение буффера ввода
	} while (!scanf("%d", &x));

	printf("Ваше число %sвходит в диапазон от 0 до 100!\n", (x >= 0 && x <= 100) ? "" : "не ");

				//  Task 2:

	int summ = 0;
	for (int i = 0; i < 10; ++i) {
		int test, num;
		do {
			printf("Введите 10 целых чисел (%d из 10): ", i);
			fseek(stdin, 0, SEEK_END);
			test = scanf("%d", &num);
		} while (!test);
		summ += num;
	}
	printf("Среднее арифметическое чисел: %d\n", summ/10);

				//  Task 3:
	
	int y;
	do {
		printf("Введите положительное число не более 1000: ");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &y);
	} while (y < 1 || y > 1000);

	printf("Положительные четные числа до указанного вами: \n");
	for (int i = 2; i <= y; i += 2) 
		printf("%d, ", i);
	*/
				//  Task 4:

	int count;
	printf("Введите какое количество строк использовать: \n");
	do {
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &count);
		printf("Невозможно это использовать...\n");
	} while (count-- < 1);
	
	for (int i = 0; i < count; ++i)
	{
		for (int j = count; j > 0; --j) 
			if (j == i)
				printf("^");
			else printf(" ");
		
		for (int z = 0; z < i; ++z)
			printf(" ");

		printf("^\n");
	}

	for (int i = 0; i <= count*2; ++i)
		printf("^");	

	return 0;
}









