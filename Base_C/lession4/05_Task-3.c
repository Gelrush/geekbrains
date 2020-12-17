/*
Описать структуру "прямая линия" которая должна 
состоять из длины и двух внутренних структур типа "точка", 
в каждой из которых должны содержаться координаты 
по оси 'х' и по оси 'у'. Описать функцию принимающую на вход 
координаты двух точек, и возвращающую структуру "линия" с подсчитанной длиной.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct dot Dot;
typedef struct straight_line Line;

struct dot {
	int x;
	int y;	
};

struct straight_line {
	float line;
	Dot coord1, coord2;
};

Line calcLine(Dot d1, Dot d2) {
	Line stl;
	stl.line = sqrt(pow(abs(d1.x - d2.x), 2) + pow(abs(d1.y - d2.y), 2));
	stl.coord1 = d1;
	stl.coord2 = d2;
	return stl;
}

int main(int argc, char const *argv[])
{
	Line stl = calcLine((Dot) {2, 4}, (Dot) {6, 19});
	printf("%.3f\n", stl.line);
	return 0;
}