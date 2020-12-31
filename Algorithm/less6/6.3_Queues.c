#include <stdio.h>


/*
	Днамические структуры данных - 
				структуры, память для которых выделяется по мере заполнения данных
		Очередь: очередь в кассу - последним зашел, последним вышел
*/
#define T char
#define SIZE 10
#define true 1 == 1
#define false 1 != 1

typedef int boolean; // псевдоним типа int

T Queue[SIZE];
int first = 0;
int end = -1;
int items = 0;

boolean enqueue(T data)
{
	if (items == SIZE) {
		printf("Queue is full\n");
		return false;
	}
	if (end == SIZE - 1) 
		end = -1;
	Queue[++end] = data;
	items++;
	return true;
}

T dequeue()
{
	if (items == 0)
	{
		printf("Queue is empty\n");
		return -1;
	} else {
		T tmp = Queue[first++];
		first %= SIZE; // if (first == SIZE) first = 0;
		items--;
		return tmp;
	}
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i) {
		enqueue('a');
		enqueue('b');
		enqueue('c');
		enqueue('d');
		enqueue('e');
		enqueue('f');
		enqueue('g');
		while (items > 0)
			printf("%c ", dequeue());
		printf("\n");
	}

	return 0;
}