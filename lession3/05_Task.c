/*
Task №2 - Arrays
by D. Frolov
on Sublime + gcc
27.09.2020
*/

#include <stdio.h>
#include <math.h>

								// ax^2 + bx + c = 0
int calsSquareEq(int a, int b, int c, double *x1, double *x2) {
	if (a == 0) return 2;

	double D = pow(b, 2) - 4 * a * c;
	if (D > 0) {
		*x1 = (-b + sqrt(D)) / (2 * a);
		*x2 = (-b - sqrt(D)) / (2 * a);
		return 1;
	} else if (D == 0) {
		*x1 = *x2 = -b / 2 * a;
		return 0;
	} else return -1;
}
								// search for even
int even(int *arr, int len) {
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (*(arr + i) % 2 != 0) {
			arr[i] *= 2;
			count++;
		}
	
	return count ? 1 : 0;
}
								// type conversion
void asShortPrint(unsigned int *a, int len) {
		for (short i = 0; i < len * 2; ++i)
			printf("%hu,", *(a + i)); 
}

int main(int argc, char const *argv[])
{
	/*					// Exercise 1 
	double x1, x2;
	int adds[3];
	printf("Введите коэффициенты квадратного уравнения (a, b, c):\n");
	for (int i = 0; i < 3; ++i) 
		scanf("%d", &adds[i]);


	switch (calsSquareEq(adds[0], adds[1], adds[2], &x1, &x2)) {
		case 1:
		printf("Дискриминант больше 0, корни: x1 = %.2f; x2 = %.2f\n", x1, x2);
		break;
		case 0:
		printf("Дискриминант равен 0, корни: x = %.2f\n", x1);
		break;
		case -1:
		printf("Дискриминант меньше 0, уравнение не имеет корней\n");
		break;
		default:
		printf("Что происходит?\n");
	}

						// Exercise 2
	const int ARRAY_LENGTH = 10;
	int arr[ARRAY_LENGTH];

	printf("Введите %d целых чисел:\n", ARRAY_LENGTH);
	for (int i = 0; i < ARRAY_LENGTH; ++i)
		scanf("%d", &arr[i]);
	
	if (even(arr, ARRAY_LENGTH))
		for (int i = 0; i < ARRAY_LENGTH; ++i)
			printf("%3d,", arr[i]);
	else printf("В массиве нет нечетных чисел");
	printf("\n");*/
	
						// Exercise 3
	unsigned int a[] = {0, 1, 2, 3, 4, 65541, 65542, 65543, 65544, 65545};
	asShortPrint(a, 10);

	return 0;
}