#include <stdio.h>

int operation = 0;

void put(int from, int to)
{
	printf("%d -> %d | ", from, to);
	if ((++operation % 5) == 0)
		printf("\n");
}

void hanoi(int from, int to, int n)
{
	int temp = from ^ to;
	if (n == 1)
		put(from, to);
	else {
		hanoi(from, temp, n - 1);
		put(from, to);
		hanoi(temp, to, n - 1);
	}
}

int main(int argc, char const *argv[])
{
	int disks = 9;
	printf("Pyramid size = %d\n", disks);
	hanoi(1, 3, disks);
	printf("\n operation = %d \n", operation);


	return 0;
}