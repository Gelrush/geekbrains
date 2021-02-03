#include <stdio.h>
#include <stdlib.h>

//==============================Supp func==============================
void swapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortIntBubble(int* arr, const int len)
{
	for (int j = 0; j < len; ++j)
		for (int i = 0; i < len - 1; ++i)
			if (arr[i] < arr [i + 1])
				swapInt(&arr[i], &arr[i + 1]);
}

//==============================Task 1==============================	
int hashFunc(char* str) 
{
	int i = 0;
	int sum = 0;
	while (str[i] != '\0') 
		sum += str[i++];
	return sum;
}

//==============================Task 2==============================	
int* numCoinGreedy(int* coins, const int SZc, const int MONEY)
{
	sortIntBubble(coins, SZc);

	int sum = 0;
	int count = 0;
	int* arrCoin = (int*) calloc(SZc + 1, sizeof(int));
	int idx = 0;

	while (sum < MONEY) {
		int i = 0;
		while (sum + coins[i] > MONEY && i < SZc - 1)
			++i;
		sum += coins[i];
		count++;
		arrCoin[++idx] = coins[i];
	}
	arrCoin[0] = count;
	return arrCoin;
}

void printCoinsColl(int* arr)
{
	printf("[ ");
	for (int i = 1; i <= arr[0]; ++i)
		printf("%d ", arr[i]);
	printf("] - coins");
}

int main(int argc, char const *argv[])
{
	char* str;
	printf("========================Task 1========================\n");
	printf("Enter a word: ");
	gets(str);
	printf("hash - %d\n", hashFunc(str));

	
	printf("========================Task 2========================\n");
	int coins[] = {5, 1, 50, 2, 10};
	const int money;
	
	printf("Enter amount of money: ");
	scanf("%d", &money);
	printf("%d cents can be collected with:\n", money);
	printCoinsColl(numCoinGreedy(coins, sizeof(coins)/sizeof(int), money));
	return 0;
}