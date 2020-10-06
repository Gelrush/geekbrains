/*
Описать структуру "прямоугольник", содержащую целочисленные 
значения длины, ширины, периметра и площади прямоугольника. 
Написать функцию, принимающую на вход указатель на структуру, 
подсчитывающую и записывающую площадь и периметр данного прямоугольника в структуру.
*/

#include <stdio.h>
#include <math.h>
typedef struct tringale Tringale;

struct tringale {
	int length;
	int width;
	int perimeter = (length + width) * 2;
	int area;
};

int perimeterTr(int x, int y) {
	return x + y + sqrt(pow(x,2) + pow(y,2));
}

int areaTr(int x, int y) {
	return x * y / 2;
}

void calcTriangle(Tringale *tr) {
	tr->perimeter = perimeterTr(tr->length, tr->width);
	tr->area = areaTr(tr->length, tr->width);
}

int main(int argc, char const *argv[])
{
	Tringale tr = {3, 4};
	calcTriangle(&tr);
	printf("Периметр: %d\nПлощадь: %d\n", tr.perimeter, tr.area);

	return 0;
}