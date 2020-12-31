#include <stdio.h>
#include <stdlib.h>

/*
	Список - базовая динамическая структура данных, 
		состоящая из узлов, каждый из которых содержит, 
		как собственно данные, так и одну или две ссылки 
		также называемые связками, на соседние узлы.
	Односвязные списки - структура в которой содержится 
		ссылка на следующий элемент списка
*/

typedef struct Node {
	int dat;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} List;

void init(List* lst) 
{
	lst->head = NULL;
	lst->size = 0;
}

void ins(List *lst, int data)
{
	Node *new = (Node*) malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;

	Node *current = lst->head;
	if (current == NULL) {
		lst->head = new;
		lst->size++;
		return;
	} else {
		while (current->next != NULL) {
			current = current->next;
		}		
		current->next = new;
		lst->size++;
	}
}

Node* rm(List *lst, int data)		// удаление элемента по его значению (первому вхождению)
{
	Node *current = lst->head;
	Node *parent = NULL;
	if (current == NULL)
		return NULL;

	while (current->next != NULL && current->dat != data) {
		parent = current;
		current = current->next;
	}
	if (current->dat != data)		// если не найден элемент
		return NULL;

	if (current == lst->head) {		// если элемент является первым
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;	// если найден перемещаем ссылку 
	lst->size--;
	return current;
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
	ins(lst, 1);
	ins(lst, 10);
	ins(lst, 20);
	ins(lst, 88);
	ins(lst, 60);
	printList(lst);

	printNode(rm(lst, 88)); printf("<- removed node\n");
	printList(lst);
	printNode(rm(lst, 2)); printf("<- removed node\n");
	printList(lst);
	return 0;
}