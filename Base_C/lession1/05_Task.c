/*
program: lession 1

author: Denis Frolov

IDE: Sublime Test + gcc
*/

#include <stdio.h>

int main()
{
	printf("Hello, World!\n");

	int a;
	printf("Введите число\n");
	scanf("%d", &a);
	printf("Квадрат введенного числа %d\n", a*a);

	printf("Uo = Ui * (R1 / (R2 + R1))\n");
	printf("Ui = Uo * (R2 + R1) / R1\n");
	printf("R1 = Uo * R2 / (Ui - Uo)\n");
	printf("R2 = Uo * Ui * R1 - R1\n");

	return 0;
}