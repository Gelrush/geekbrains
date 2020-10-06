/*
Описать функцию, возвращающую строку с двоичным 
представлением положительного целого десятичного числа, 
переданного в аргументе этой функции.
*/

#include <stdio.h> 
#include <math.h> 

void toBinary(int num, char *out) { 
	int log = (int) log2(num); 
	int temp = num; 
	for (int i = 0; i <= log; ++i) { 
		*(out + i) = ((num & temp) >> log) ? '1' : '0'; 
		num <<= 1; 
	} 
}

int main(int argc, char const *argv[]) 
{ 
int num; 
char arr[255] = ""; 
printf("Введите число для перевода его в двоичный формат:\n");
scanf("%d", &num); 
toBinary(num, arr); 

printf("%s\n", arr); 

return 0; 
}