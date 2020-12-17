#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//--------------------------------------------------№1
const char DIGITS[2][2] = {"0", "1"};

void recTrans(char* bin, int num) 
{
	if (num <= 0) return;
	recTrans(bin, num / 2);
	strcat(bin, (num % 2 == 0) ? "0" : "1");
	

	/*if (num > 1)
		recTrans(bin, num / 2);
	if (num == 0)
		strcpy(bin, DIGITS[0]);
	if (num == 1)
		strcat(bin, DIGITS[1]);
	else strcat(bin, DIGITS[num % 2]);*/		
}

//--------------------------------------------------№2.1
int recPow(int base, int index)
{
	if (index <= 0) return 1;
	return base * recPow(base, index - 1);

	/*if (base == 0)
		return 0;
	if (index == 1)
		return base;
	if (index > 1)
		return base * recPow(base, index - 1);*/
}

//--------------------------------------------------№2.2
int recPowAlt(int base, int index)
{
	if (index <= 0) return 1;
	if (index % 2 == 1)
		return base * recPowAlt(base, index - 1);
	else
		return recPowAlt(base * base, index / 2);

	/*if (base == 0)
		return 0;
	if (index == 1)
		return base;
	if (index % 2 == 1)
		return base * recPowAlt(base, index - 1);
	else
		return recPowAlt(base * base, index / 2);*/	
}

//--------------------------------------------------№3 (перемещение короля по доске с препятствиями)
int routes(int x, int y, int** board)		// <по правилам король может ходить еще и по диагонали>
{
	if (x == 0 && y == 0)
		return 0;
	if (board[x][y] == -1)
		return 0;
	if (x == 0) {
		if (routes(x, y - 1, board) == 0 && y != 1) return 0;
		return 1;
	}
	if (y == 0) {
		if (routes(x - 1, y, board) == 0 && x != 1) return 0;
		return 1;
	}
	if (x == 1 && y == 1)
		return routes(x, y - 1, board) + routes(x - 1, y, board) + 1;
	else return routes(x, y - 1, board) + routes(x - 1, y, board) + routes(x - 1, y - 1, board);

	/*if (x == 0 && y == 0)
		return 0;
	if (board[x][y] == -1)
		return 0;
	if (x == 0 || y == 0)
		return 1;
	if (x == 1 && y == 1)
		return routes(x, y - 1, board) + routes(x - 1, y, board) + 1;
	else return routes(x, y - 1, board) + routes(x - 1, y, board) + routes(x - 1, y - 1, board);*/
}

void printBoard(int** board, int x, int y)
{
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j)
			printf("%6d", board[i][j]);
		puts("\n");
	}
}

int** enterLet(int x, int y, int countlet)	// инициализация доски и рандомное заполнение препятствий
{
	int **table = (int**) malloc(x * sizeof(int));
	for (int i = 0; i < x; ++i)
		*(table + i) = (int*) calloc(y, sizeof(int));

	srand(time(NULL));
	int tempX;
	int tempY;
	for (int i = 0; i < countlet; ++i) {
		do {
			tempX = rand()%x;
			tempY = rand()%y;
		} while (table[tempX][tempY] == -1 || (tempX == 0 && tempY == 0));
		table[tempX][tempY] = -1;
	}

	return table;
}





int main(int argc, char const *argv[])
{
	//--------------------------------------------------№1
	char result[255] = "";
	int num;
	printf("Введите число: ");
	scanf("%d", &num);
	recTrans(result, num);
	printf("В двоичной систете счисления: %s\n", result);
	//--------------------------------------------------№2.1
	int x, y;
	printf("Введите основание и степень возведения: ");
	scanf("%d%d", &x, &y);
	printf("Результат (обычный способ): %d\n", recPow(x, y));
	//--------------------------------------------------№2.2
	printf("Введите основание и степень возведения: ");
	scanf("%d%d", &x, &y);
	printf("Результат (свойство четности): %d\n", recPowAlt(x, y));
	//--------------------------------------------------№3
	const int sizeX = 8;
	const int sizeY = 8;
	int countlet;
	int** let;

	printf("Укажите количество препятствий: ");
	scanf("%d", &countlet);

	let = enterLet(sizeX, sizeY, countlet);
	for (int i = 0; i < sizeX; ++i)
		for (int j = 0; j < sizeY; ++j)
			if (let[i][j] == 0)
				let[i][j] = routes(i, j, let);

	printBoard(let, sizeX, sizeY);

	return 0;
}