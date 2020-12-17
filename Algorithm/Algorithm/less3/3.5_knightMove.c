#include <stdio.h>

#define HEIGHT 8
#define WIDTH 8
#define QUEENS 8
#define KNIGHT HEIGHT * WIDTH - 1

int board[HEIGHT][WIDTH];

int possible[][2] = {
	{2, 1}, {-2, 1}, {1, 2}, {-1, 2},
	{2, -1}, {-2, -1}, {1, -2}, {-1, -2}
};

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

int isPossible(int x, int y) 
{
	return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && board[x][y] == 0;
}

int knightMove(int x, int y, int move) 
{
	int nextX;
	int nextY;
	board[x][y] = move;
	if (move > KNIGHT) return 1;
	for (int i = 0; i < 8; ++i) {
		nextX = x + possible[i][1];
		nextY = y + possible[i][0];
		if (isPossible(nextX, nextY) && knightMove(nextX, nextY, move + 1))
			return 1;
	}
	board[x][y] = 0;
	return 0;
}

int main(int argc, char const *argv[])
{
	annull();
	knightMove(1, 0, 1);
	printBoard();
	return 0;
}