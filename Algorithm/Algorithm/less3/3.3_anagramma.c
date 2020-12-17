#include <stdio.h>

void rotate(char* word, int size, int n)
{
	int i; 
	int pos = size - n;
	char temp = word[pos];
	for (int i = pos + 1; i < size; ++i)
		word[i - 1] = word[i];
	word[i - 1] = temp;
}

void display(char* word, int size) 
{
	for (int i = 0; i < size; ++i)
		printf("%c", word[i]);
	printf("\n");
}

void getAnagram(char* word, int size, int n) 
{
	if (n == 1) 
		return;
	for (int i = 0; i < n; ++i) {
		getAnagram(word, size, n - 1);
		if (n == 2)
			display(word, size);
		rotate(word, size, n);
	}
}

int main(int argc, char const *argv[])
{
	int size = 4;
	char arr[64] = {'m', 'o', 'r', 'e'};
	getAnagram(arr, size, size);

	return 0;
}