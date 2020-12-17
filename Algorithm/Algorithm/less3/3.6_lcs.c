#include <stdio.h>
#include <stdlib.h>

//X(1..N) abcbdab
//Y(1..M) bcdb

//LCS(x, y) = LCS(x[i+1], y[i+1]) +1, если x[i] = y[i]
//LCS(x, y) = максимальное из LCS(x[i], y[i+1]), LCS(x[i+1], y[i]), если x[i] != y[i]
//LCS(x ,y) = 0, если x = 0 или y = 0

int lcs_len(char* a, char* b) // длина общей большей подпоследовательности
{
	if (*a == '\0' || *b == '\0')
		return 0;
	if (*a == *b) 
		return 1 + lcs_len(a + 1, b + 1); // a + 1 удаляет первый символ
	else {
		int x1 = lcs_len(a + 1, b);
		int x2 = lcs_len(a, b + 1);
		return (x1 > x2) ? x1 : x2;
	}
}

int main(int argc, char const *argv[])
{
	char* a = "abcbdab";
	char* b = "bcdb";

	printf("Длина наибольшей общей последовательности: %d\n", lcs_len(a, b));

	return 0;
}