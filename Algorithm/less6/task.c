#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
======================Task #1======================
*/
#define SIZE 10

typedef struct {
	int pr;
	int dat;
} Node;

Node* arrPrQueueEx[SIZE];
int items;

int searchPrQueue() // линейный поиск приоритетного элемента
{
	int idxMin = 0;
	for (int i = 1; i < items; ++i)
		if (arrPrQueueEx[i]->pr < arrPrQueueEx[idxMin]->pr) 
			idxMin = i;
	
	return idxMin;
}

void init() // инициализация очереди
{
	for (int i = 0; i < SIZE; ++i)
		arrPrQueueEx[i] = NULL;

	items = 0;
}

void close() // совобождение памяти
{
	for (int i = 0; i < SIZE; ++i)
		free(arrPrQueueEx[i]);
}

void insert(int pr, int dat) // добавление в очередь
{
	if (items == SIZE) {
		printf("Queue is full\n");
		return;
	}
	
	Node *tmp = (Node*) malloc(sizeof(Node));
	tmp->pr = pr;
	tmp->dat = dat;
	arrPrQueueEx[items++] = tmp;
}

Node* pull() // вывод приоритетного элемента со смещением
{
	if (items == 0) 
		return NULL;
	
	int idx = searchPrQueue();
	Node *tmp = arrPrQueueEx[idx];
	while (idx < items) {		
		arrPrQueueEx[idx] = arrPrQueueEx[idx + 1];
		++idx;
	}

	items--;
	return tmp;
}

Node* peek() // вывод приоритетного элемента
{
	if (items == 0) 
		return NULL;
	return arrPrQueueEx[searchPrQueue()];
}

void printNode(Node *x) // печать элемента
{
	if (x == NULL)
			printf("[*,*] ");
		else
			printf("[%d,%d] ", x->pr, x->dat);
}

Node* printQueue() // печать очереди
{
	printf("[ ");
	for (int i = 0; i < SIZE; ++i)
		printNode(arrPrQueueEx[i]);
	printf("]\n");
}

/*
======================Task #2======================
*/
#define T char
#define binSIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean; 

int cursor = -1;
T Stack[binSIZE];

boolean push(T data)
{
	if (cursor < binSIZE) {
		Stack[++cursor] = data;
		return true;
	} else {
		printf("Stack overflow\n");
		return false;
	}
}

T pop() {
	if (cursor != -1) {
		return Stack[cursor--];
	} else {
		printf("Stack is empty\n");
		return -1;
	}
}

void fillStack(int num)
{
	if (num == 0) return;
	push((num % 2) ? '1' : '0');
	fillStack(num / 2);
}

void convertBin(char *bin, int num)
{
	fillStack(num);
	int i = 0;
	while (cursor != -1) 
		bin[i++] = pop();
	bin[i] = '\0';
}


int main(int argc, char const *argv[])
{
	init();
	insert(10, 11);
	insert(5, 22);
	insert(4, 33);
	insert(2, 33);
	insert(2, 33);
	insert(1, 44);
	insert(5, 66);
	insert(6, 77);
	insert(8, 88);
	insert(3, 99);
	insert(11, 11);

	printQueue();
	for (int i = 0; i < 10; ++i)
	{
		printNode(pull());
		puts("");
	}
	close();




	int num;
	char binNum[binSIZE];
	printf("Введите число: ");
	scanf("%d", &num);
	
	printf("Двоичная запись числа: ");
	convertBin(binNum, num);
	printf("%s\n", binNum);


	return 0;
}