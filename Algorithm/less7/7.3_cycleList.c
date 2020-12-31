#include "func.h"

/*
	Список - базовая динамическая структура данных, 
		состоящая из узлов, каждый из которых содержит, 
		как собственно данные, так и одну или две ссылки 
		также называемые связками, на соседние узлы.
	Циклические списки - структура в которой содержится 
		ссылка на следующий/предыдущий элемент списка, 
		а последний элемент указывает на первый элемент (кольцо)
*/

//typedef struct OLNode {
//	int dat;
//	struct OLNode *next;
//} OLNode;
//
//typedef struct {
//	OLNode *head;
//	int size;
//} OLList;


void insertCyclic(OLList *lst, int data)
{
	OLNode *new = (OLNode*) malloc(sizeof(OLNode));
	new->dat = data;
	new->next = lst->head;

	OLNode *current = lst->head;
	if (current == NULL) {
		lst->head = new;
		new->next = lst->head;
		lst->size++;
		return;
	} else {
		while (current->next != lst->head)	//           находим последний элемент
			current = current->next;		//    (у него next будет указзывать на head)
		current->next = new;				// и присваиваем ему ссылку на добавленный элемент
		lst->size++;
	}
}

OLNode* rmCyclic(OLList *lst, int data)
{
	OLNode *current = lst->head;
	OLNode *parent = NULL;

	if (current == NULL)
		return NULL;
	
	while (current->next != lst->head && current->dat != data) {
		parent = current;
		current = current->next;
	}
	if (current->dat != data)
		return NULL;

	if (current == lst->head) {
		if (current->next == lst->head) {
			lst->head = NULL;
			lst->size--;
			return current;
		} else {
			OLNode *tmp = current;
			while (current->next != lst->head)
				current = current->next;
			lst->head = tmp->next;
			current->next = lst->head;
			lst->size--;
			return tmp;
		}
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

void printCyclic(OLList *lst) 
{
	OLNode *current = lst->head;
	if (current == NULL)
		PrintOLNode(current);
	else {
		do {
			PrintOLNode(current);
			current = current->next;
		} while (current != lst->head);
	}
	printf("Size: %d \n", lst->size);
}


int main(int argc, char const *argv[])
{
	OLList *l = (OLList*) malloc(sizeof(OLList));
	InitOLList(l);
	printCyclic(l);
	insertCyclic(l, 1);
	insertCyclic(l, 10);
	insertCyclic(l, 88);
	insertCyclic(l, 77);
	insertCyclic(l, 2);
	printCyclic(l);

	PrintOLNode(rmCyclic(l, 1)); printf("<- remove node\n");
	printCyclic(l);
	PrintOLNode(rmCyclic(l, 2)); printf("<- remove node\n");
	printCyclic(l);
	PrintOLNode(rmCyclic(l, 10)); printf("<- remove node\n");
	printCyclic(l);

	return 0;
}