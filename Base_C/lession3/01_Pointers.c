#include <stdio.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
	int a = 50;
	printf("Значение переменной 'а': %d\n\n", a);
	printf("Адрес переменной 'a' : %p\n\n", &a);

	int *pointer = &a; // запись в указатель ссылки на переменную

	printf("Значение указателя 'pointer': %p\n\n", pointer);
	printf("Адрес указателя 'pointer': %p\n\n", &pointer);
	printf("Указатель ссылается на значение: %d\n\n", *pointer);

	*pointer = 70;
	printf("Значение 'а' после модификации указателя: %d\n\n", a);

	int x = 5, y = 7;
	printf("x = %d, y = %d\n", x, y);

	swap(&x, &y);
	printf("Вызван функцию swap используя указатели: x = %d, y = %d\n", x, y);

	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}