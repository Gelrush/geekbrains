#include <stdio.h>
#include <stdlib.h>

/*
	Список - базовая динамическая структура данных, 
		состоящая из узлов, каждый из которых содержит, 
		как собственно данные, так и одну или две ссылки 
		также называемые связками, на соседние узлы.
	Двусвязные списки - структура в которой содержится 
		ссылка на предыдущий и на следующий элементы списка
*/

typedef struct Node {
	int dat;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct {
	Node *head;
	Node *tail;
	int size;
} List;

void init(List* lst) 
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void pushFront(List *lst, int data)
{
	Node *new = (Node*) malloc(sizeof(Node));
	new->dat = data;
	new->prev = NULL;
	new->next = lst->head;
	if (lst->head != NULL)
		lst->head->prev = new;

	if (lst->tail == NULL)
		lst->tail = new;

	lst->head = new;
	lst->size++;
}

void pushBack(List *lst, int data)
{
	Node *new = (Node*) malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;
	new->prev = lst->tail;

	if (lst->tail != NULL)
		lst->tail->next = new;

	if (lst->head == NULL)
		lst->head = new;

	lst->tail = new;
	lst->size++;
}

Node* rmFront(List *lst)
{
	if (lst->head == NULL)
		return NULL;

	Node *tmp = lst->head;
	lst->head = lst->head->next;
	if (lst->head != NULL)
		lst->head->prev = NULL;

	if (tmp == lst->tail)		
		lst->tail = NULL;

	lst->size--;
	return tmp;
}

Node* rmBack(List *lst)
{
	if (lst->tail == NULL)
		return NULL;

	Node *tmp = lst->tail;
	lst->tail = lst->tail->prev;
	if (lst->tail != NULL)
		lst->tail->next = NULL;

	if (tmp == lst->head)	
		lst->head = NULL;

	lst->size--;
	return tmp;
}

void printNode(Node *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%d] ", n->dat);
}

void printList(List *lst) 
{
	Node *current = lst->head;
	if (current == NULL)
		printNode(current);
	else {
		do {
			printNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf("Size: %d \n", lst->size);
}

int main(int argc, char const *argv[])
{
	List *lst = (List*) malloc(sizeof(List));
	init(lst);
	printList(lst);
	pushFront(lst, 1);
	pushFront(lst, 10);
	pushBack(lst, 20);
	pushBack(lst, 88);
	pushFront(lst, 60);
	printList(lst);

	printNode(rmFront(lst)); printf("<- removed node Front\n");
	printList(lst);
	printNode(rmBack(lst)); printf("<- removed node Back\n");
	printList(lst);

	printNode(rmFront(lst)); printf("<- removed node Front\n");
	printList(lst);
	printNode(rmBack(lst)); printf("<- removed node Back\n");
	printList(lst);
	printf("head/tail = ");
	printNode(lst->head);
	printNode(lst->tail);

	return 0;
}