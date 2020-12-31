#include "func.h"

/*
	Список - базовая динамическая структура данных, 
		состоящая из узлов, каждый из которых содержит, 
		как собственно данные, так и одну или две ссылки 
		также называемые связками, на соседние узлы.
	Очредь - первым зашел, первым вышел
*/

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;


//typedef struct TLNode {
//	int dat;
//	struct TLNode *next;
//	struct TLNode *prev;
//} TLNode;
//
//typedef struct {
//	TLNode *head;
//	TLNode *tail;
//	int size;
//} TLList;
//
//void InitTLList(TLList* lst) 
//{
//	lst->head = NULL;
//	lst->tail = NULL;
//	lst->size = 0;
//}

boolean enqueue(TLList *queue, T value)
{
	TLNode *tmp = (TLNode*) malloc(sizeof(TLNode));
	if (tmp == NULL) {							// Если в оперативной памяти не осталось места
		printf("Out of memory\n");
		return false;
	}
	tmp->dat = value;
	tmp->next = NULL;
	tmp->prev = queue->tail;

	if (queue->tail != NULL)					// если очередь не пуста
		queue->tail->next = tmp;

	if (queue->head == NULL)					// если очередь пуста
		queue->head = tmp;

	queue->tail = tmp;
	queue->size++;
	return true;
}

T dequeue(TLList *queue)
{
	if (queue->size == 0) {
		printf("Stack is empty\n");
		return -1;
	}
	TLNode *tmp = queue->head;
	T data = queue->head->dat;

	queue->head = queue->head->next;

	if (queue->head != NULL)					// если в списке еще есть элементы
		queue->head->prev = NULL;

	if (tmp == queue->tail)						// если в списке был один элемент
		queue->tail = NULL;

	free(tmp);
	queue->size--;
	return data;
}

void printTLCharNode(TLNode *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%c] ", n->dat);
}

void printTLCharList(TLList *lst) 
{
	TLNode *current = lst->head;
	if (current == NULL)
		printTLCharNode(current);
	else {
		do {
			printTLCharNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf("Size: %d \n", lst->size);
}

int main(int argc, char const *argv[])
{
	TLList *q = (TLList*) malloc(sizeof(TLList));
	InitTLList(q);
	enqueue(q, 'a');
	enqueue(q, 'b');
	enqueue(q, 'c');
	enqueue(q, 'd');
	enqueue(q, 'e');
	printTLCharList(q);

	printf("%c <- deleted\n", dequeue(q));
	printf("%c <- deleted\n", dequeue(q));
	printTLCharList(q);

	printf("%c <- deleted\n", dequeue(q));
	printf("%c <- deleted\n", dequeue(q));
	printf("%c <- deleted\n", dequeue(q));
	printf("%c <- deleted\n", dequeue(q));
	printTLCharList(q);

	return 0;
}