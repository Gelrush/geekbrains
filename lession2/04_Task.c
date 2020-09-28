/*
Task №2 - Cycle
by D. Frolov
on Sublime + gcc
27.09.2020
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
				//  Exercise 1:
	
	int x;

	do {	// цикл проверки введенного значенияна число
	printf("Введите целое число: ");
	fseek(stdin, 0, SEEK_END);				// очищение буффера ввода
	} while (!scanf("%d", &x));

	printf("Ваше число %sвходит в диапазон от 0 до 100!\n", (x >= 0 && x <= 100) ? "" : "не ");

				//  Exercise 2:

	int summ = 0;
	const int NUMS = 10;	// используемые числа не ввода лучше выносить константой
	for (int i = 0; i < NUMS; ++i) {
		int test, num;
		do {	// цикл проверки введенного значенияна число
			printf("Введите %d целых чисел (%d из %d): ", NUMS, i, NUMS);
			fseek(stdin, 0, SEEK_END);
			test = scanf("%d", &num);
		} while (!test);
		summ += num;
	}
	printf("Среднее арифметическое чисел: %d\n", summ/NUMS);

				//  Exercise 3:
	
	int y;
	do {	// цикл проверки введенного значенияна число
		printf("Введите положительное число не более 1000: ");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &y);
	} while (y < 1 || y > 1000);

	printf("Положительные четные числа до указанного вами: \n");
	for (int i = 2; i <= y; i += 2) 
		printf("%d, ", i);
	
				//  Exercise 4:
	
	int count;
	printf("\nВведите какое количество строк использовать: \n");
	while (!scanf("%d", &count) || (count-- < 1)) {
		fseek(stdin, 0, SEEK_END);
		printf("Невозможно это использовать...\n");
	}
	
	for (int i = 0; i < count; ++i)
	{
		for (int j = count; j > -i; --j) 
			if (j == i)
				printf("^");
			else printf(" ");

		printf("^\n");
	}
	
	for (int i = 0; i <= count*2; ++i)
		printf("^");	
	

	/*
	count++;
	for (int i = 0; i < count; ++i)
	{
		for (int j = count; j > -i; --j) 
			if (j <= i)
				printf("^");
			else printf(" ");
		printf("^\n");
	}
	*/
	return 0;
}









