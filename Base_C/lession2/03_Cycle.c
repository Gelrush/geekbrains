#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 20;

	while (a < b) 
		printf("%d\t", a++); // сначала вывод, потом инкремент

	int number;
	printf("\nВведите чисто: ");
	scanf("%d", &number);
	int d = 0;
	int i = 1;

	while (i <= number) {
		if (number % i++ == 0)
			d++;
		else continue; // отбрасывание далнейших действия итерации
		if (d == 3) break;
	}
	printf("Введенное число %d - %sявляется простым\n", 
		number, d == 2 ? "" : "не ");   // определение простого числа

	float first;
	float second;
	float result;
	unsigned char symbol;

	printf("Введите первый операнд: ");
	scanf("%f", &first);
	printf("Введите действие: ");
	fseek(stdin, 0, SEEK_END); // очищение буффера ввода
	scanf("%c", &symbol);
	if (symbol == '/')
		do {
			printf("Введите второй операнд: ");
			scanf("%f", &second);
		} while (second == 0);
	else {
		printf("Введите второй операнд: ");
		scanf("%f", &second);
	}

	switch (symbol) { // калькулятор
		case '*':
		result = first * second;
		break;
		case '/':
		result = first / second;
		break;
		case '+':
		result = first + second;
		break;
		case '-':
		result = first - second;
		break;
		default:
		printf("Я не знаю такого действия\n");
		return 0;
	}
	printf("%.02f %c %.02f = %.02f\n", first, symbol, second, result);
	
	return 0;
}