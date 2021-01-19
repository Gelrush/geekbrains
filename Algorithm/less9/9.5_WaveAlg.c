#include "func.h"

/*
	Граф - совокупность точек, соединенных линиями. 
		Точки называются вершинами, или узлами, а линии – ребрами, или дугами.
		Степень входа вершины – количество входящих в нее ребер, 
		степень выхода – количество исходящих ребер.

		Волновой алгоритм Ли поиска - поиск кратчайшего пути графе,
			применяется используя препятствия, применяетсяв gamedef.
*/

#define HEIGHT 8
#define WIDTH 10
const int BLANK = -2;				// значение не посещенных ячеек
const int OBSTACLE = -1;			// значение препятствий

int pointX[HEIGHT * WIDTH];			// хранение координат точек пути
int pointY[HEIGHT * WIDTH];
int len;							// длина пути

int lee(int** grid, int sx, int sy, int ex, int ey)
{
	int dx[4] = {1, 0, -1, 0};		// Возможные ходы по X и Y
	int dy[4] = {0, 1, 0, -1};

	int x;							// счетчики циклов при проходе по полю
	int y;
	int vector;						// возможные варианты смещения относительно ткучей точки
	int distance = 0;				// количество шагов до ячейки
	boolean stop;					// флажек тупика

	if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE)
		return false;					// если начало или конец находятся на препятствиях

	grid[sy][sx] = 0; 				// стартовая точка
	do {
		stop = true;
		for (y = 0; y < HEIGHT; ++y) {
			for (x = 0; x < WIDTH; ++x) {	
				if (grid[y][x] == distance) {	// для начальной точки
					for (vector = 0; vector < 4; ++vector) { // проверяем каждый возможный ход
						int nextX = x + dx[vector];
						int nextY = y + dy[vector];
						if (nextX >= 0 && nextX < WIDTH &&	// проверяем границы матрицы
							nextY >= 0 && nextY < HEIGHT &&
							grid[nextY][nextX] == BLANK) {	// и что новая ячейка не посещалась
								stop = false;
								grid[nextY][nextX] = distance + 1;
						}
					}
				}
			}
		}
		distance++;
	} while (!stop && grid[ey][ex] == BLANK);

	if (grid[ey][ex] == BLANK) return false;

	len = grid[ey][ex];				
	x = ex;
	y = ey;
	while (distance > 0) {			// заполнение массива кратчайшего пути
		printf("x=%d, y=%d\n", x, y);
		pointX[distance] = x;
		pointY[distance] = y;
		distance--;
		for (vector = 0; vector < 4; ++vector) { 
			int nextX = x + dx[vector];
			int nextY = y + dy[vector];
			if (nextX >= 0 && nextX < WIDTH &&	
				nextY >= 0 && nextY < HEIGHT &&
				grid[nextY][nextX] == distance) {
					x = nextX;
					y = nextY;
			}
		}
	}
	return len;
}


int main(int argc, char const *argv[])
{
	int** matrix = init2dIntArray(matrix, HEIGHT, WIDTH);
	for (int i = 0; i < HEIGHT; ++i) 
		for (int j = 0; j < WIDTH; ++j) 
			set2dInt(matrix, i, j, BLANK);
	set2dInt(matrix, 4, 3, OBSTACLE);
	set2dInt(matrix, 4, 4, OBSTACLE);
	set2dInt(matrix, 4, 5, OBSTACLE);
	set2dInt(matrix, 4, 6, OBSTACLE);

	print2dIntArray(matrix, HEIGHT, WIDTH);
	puts("");

	int length = lee(matrix, 2, 2, 7, 5);
	print2dIntArray(matrix, HEIGHT, WIDTH);
	puts("");
	printIntArray(pointX, length);
	printIntArray(pointY, length);


	return 0;
}