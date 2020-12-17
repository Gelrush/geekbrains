#include <stdio.h>

#define HEIGHT 8
#define WIDTH 8
#define QUEENS 8

int board[HEIGHT][WIDTH];

void annull()
{
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			board[i][j] = 0;
}

void printBoard()
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j)
			printf("%3d", board[i][j]);
		printf("\n");
	}
			
}

int checkQueen(int x, int y)
{
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			if (board[i][j] != 0)			// если в позиции стоит королева
				if (!(i == x && j == y)) {	// и это не та же самая фигура
					if (i - x == 0 || j - y == 0) return 0; // если сходится горизоталь или вертикаль
					if (abs(i - x) == abs(j - y)) return 0; // если сходится по диагонали
				}
	return 1;

}

int checkBoard()
{
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			if (board[i][j] != 0) 
				if (checkQueen(i, j) == 0)
					return 0;
	return 1;
}

int queens(int n)
{
	if (checkBoard() == 0) return 0;
	if (n == QUEENS + 1) return 1;
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			if (board[i][j] == 0) {
				board[i][j] = n;
				if (queens(n + 1))
					return 1;
				board[i][j] = 0;
			}
	return 0;
}

int main(int argc, char const *argv[])
{
	annull();
	queens(1);
	printBoard();

	return 0;
}