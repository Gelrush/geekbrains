#include <stdio.h>

int triangle(int n)
{
	int result = 0;
	if (n == 1)
		result++;
	else result += n + triangle(n - 1);
	return result;
}

void printPyramid(int n)
{
	for (int i = 1; i <= n; ++i) {
		int amnt = i;
		char shift[5];
		sprintf(shift, "%%%dd", n + 1 - i); // %3d
		printf(shift, i);
		while (--amnt)			
			printf("%2d", i);	
		printf("\n");
	}
}

void printTriangle(int n)
{
	int prev = 0;
	while (n > 0) {
		prev++;
		n -= prev;
		printf("%s%d", (prev > 1) ? " + " : "", prev);
	}
}

int main(int argc, char const *argv[])
{
	const int num = 8;
	printf("%d\n", triangle(num));
	printPyramid(num);
	printTriangle(triangle(num));
	return 0;
}