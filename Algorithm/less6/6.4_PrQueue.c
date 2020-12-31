#include <stdio.h>
#include <stdlib.h>

/*
	Днамические структуры данных - 
				структуры, память для которых выделяется по мере заполнения данных
		Приоритетная очередь: структура с парой значений (ключ и данные), 
		среди которых ключ это приоритет. Возможны 2 реализации:
			очередь с приоритетным исключением (при удалении элементов выбирается самый приоритетный) -
				как при линейном поиске
			очередь с приоритетным включеним (при добавлении элемента, ставится согласно его приоритету) -
				как при сортировке вставками
		Двустороняя очередь (Дек): очередб где можно добавлять либо удалять элементы с обоих сторон
*/

#define SZ 10 // размер очереди

typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int head;		// индекс начала очереди
int tail;		// индекс конца очереди
int items;		// количесво элементов в очереди

void init()
{
	for (int i = 0; i < SZ; ++i)
		arr[i] = NULL;

	head = 0;
	tail = 0;
	items = 0;
}

void ins(int pr, int dat)
{
	Node *node = (Node*) malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;

	int flag;
	if (items == 0) {
		arr[tail++] = node;
		items++;
	} else if (items == SZ) {
		printf("Queue is full\n");
		return;
	} else {
		int i, idx;
		Node *tmp;
		
		for (i = head; i < tail; ++i) {
			idx = i % SZ;
			if (arr[idx]->pr > pr) 
				break;
			else 
				idx++;
		}

		flag = idx % SZ;
		i++;
		while (i <= tail) {
			idx = i % SZ;
			tmp = arr[idx];
			arr[idx] = arr[flag];
			arr[flag] = tmp;
			i++;
		}
		arr[flag] = node;
		items++;
		tail++;
	}
}

Node* rem()
{
	if (items == 0)
		return NULL;
	else {
		int idx = head++ % SZ;
		Node *tmp = arr[idx];
		arr[idx] = NULL;
		items--;
		return tmp;
	}
}

void printQueue() 
{
	printf("[ ");
	for (int i = 0; i < SZ; ++i)
		if (arr[i] == NULL)
			printf("[*, *] ");
		else
			printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
	printf("]\n");
}

int main(int argc, char const *argv[])
{
	init();
	ins(4, 11);
	ins(2, 22);
	ins(1, 33);
	ins(5, 44);
	ins(6, 55);
	ins(6, 66);
	ins(7, 77);
	ins(1, 88);
	ins(6, 99);
	ins(8, 100);
	printQueue();
	for (int i = 0; i < 7; ++i)
	{
		Node* n = rem();
		printf("pr=%d, dat=%d\n", n->pr, n->dat);
	}
	printQueue();

	ins(1, 100);
	ins(3, 101);
	ins(6, 103);
	printQueue();

	for (int i = 0; i < 5; ++i)
	{
		Node* n = rem();
		printf("pr=%d, dat=%d\n", n->pr, n->dat);
	}
	printQueue();
	printf("head=%d, tail=%d\n", head, tail);
	return 0;
}