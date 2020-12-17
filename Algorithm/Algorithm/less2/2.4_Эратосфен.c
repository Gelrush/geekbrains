#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int COUNT;
	scanf("%d", &COUNT);

	int arr[COUNT] = {2};
	int capacity = 2;
	
	for (int i = 3; i < COUNT; ++i) {
		int isPrime = 1;
		for (int j = 0; j < capacity; ++j) {
			if (i % arr[j] == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime)
			arr[capacity++] = i;
	}

	for (int i = 0; i < capacity; ++i)
		printf("%d ", arr[i]);	

	return 0;
}