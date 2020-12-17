#include <stdio.h>
#include <stdlib.h>

int routes(int x, int y)
{
	if (x == 0 && y == 0)
		return 0;
	if (x == 0 || y == 0)
		return 1;
	if (x == 1 && y == 1)
		return routes(x, y - 1) + routes(x - 1, y) + 1;
	else return routes(x, y - 1) + routes(x - 1, y) + routes(x - 1, y - 1);
}

int main(int argc, char const *argv[])
{
	const int sizeX = 8;
	const int sizeY = 8;
	for (int i = 0; i < sizeX; ++i) {
		for (int j = 0; j < sizeY; ++j)
			printf("%6d", routes(i, j));
		printf("\n\n");
		}

	return 0;
}