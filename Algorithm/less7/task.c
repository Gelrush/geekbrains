#include <stdio.h>
#include <stdlib.h>

//=============================================================
//===========================Supp Code=========================
//=============================================================
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
	T dat;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

Stack* initStack() 
{
	Stack *stack = (Stack*) malloc(sizeof(Stack));

	stack->head = NULL;
	stack->size = 0;

	return stack;
}

boolean push(Stack *stack, T value)
{
	Node *tmp = (Node*) malloc(sizeof(Node));
	if (tmp == NULL) {
		printf("Stack overflow\n");
		return false;
	}
	tmp->dat = value;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
	return true;
}

T pop(Stack *stack)
{
	if (stack->size == 0) {
		return -1;
	}
	Node *tmp = stack->head;
	T data = stack->head->dat;

	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}


typedef struct OLNode {
	int dat;
	struct OLNode *next;
} OLNode;

typedef struct {
	OLNode *head;
	int size;
} OLList;

void InitOLList(OLList* lst) 
{
	lst->head = NULL;
	lst->size = 0;
}

void InsertOLList(OLList *lst, int data)
{
	OLNode *new = (OLNode*) malloc(sizeof(OLNode));
	new->dat = data;
	new->next = NULL;

	OLNode *current = lst->head;
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

OLNode* RmOLList(OLList *lst, int data)		
{
	OLNode *current = lst->head;
	OLNode *parent = NULL;
	if (current == NULL)
		return NULL;

	while (current->next != NULL && current->dat != data) {
		parent = current;
		current = current->next;
	}
	if (current->dat != data)		
		return NULL;

	if (current == lst->head) {		
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;	
	lst->size--;
	return current;
}

void PrintOLNode(OLNode *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%d] ", n->dat);
}

void PrintOLList(OLList *lst) 
{
	OLNode *current = lst->head;
	if (current == NULL)
		PrintOLNode(current);
	else {
		do {
			PrintOLNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf("Size: %d \n", lst->size);
}

//=============================================================
//=========================Task 1==============================
//=============================================================
typedef struct Options {
	char sym1;
	char sym2;
	unsigned char flags;				// bit state
	unsigned char point;				// bit flag
} Options;

Options* initOpt(char sym1, char sym2)
{
	Options *opt = (Options*) malloc(sizeof(Options));

	opt->sym1 = sym1;
	opt->sym2 = sym2;
	opt->flags = 0x01;
	opt->point = 0;

	return opt;
}


void corrExp(Stack *st, Options **arr)
{
	char tmp;
	while (true) {
		tmp = pop(st);
		if (tmp == -1) 
			return;

		int i = 0;
		while (arr[i] != NULL) {
			if (tmp == arr[i]->sym2) {
				arr[i]->point |= arr[i]->flags;
				arr[i]->flags *= 2;
			}
			if (tmp == arr[i]->sym1) {
				if (arr[i]->flags != 1) 
					arr[i]->flags /= 2;
				else 
					arr[i]->flags -= 2;

				arr[i]->point ^= arr[i]->flags;
			}
			i++;
		}
	}
}

void initBtkCheck(Options **arr, const char* syms)
{
	int i = 0;
	while (syms[i] != '\0') {
		arr[i / 2] = initOpt(syms[i], syms[i + 1]);
		i += 2;
		arr[i / 2] = NULL;
	}
}



//=============================================================
//=========================Task 2==============================
//=============================================================
void copyOLList(OLList *lstFirst, OLList *lstSecond)		// copy by value
{
	OLNode *currentSec = lstSecond->head;
	while (currentSec != NULL) {
		InsertOLList(lstFirst, currentSec->dat);
		currentSec = currentSec->next;
		
	}
}

void replaceOLList(OLList *lstFirst, OLList *lstSecond)		// copy pointers
{
	OLNode *tailFirst = lstFirst->head;
	while (tailFirst->next != NULL)
		tailFirst = tailFirst->next;

	tailFirst->next = lstSecond->head;
	lstFirst->size += lstSecond->size;
}


//=============================================================
//=========================Task 3==============================
//=============================================================
int recDefSort(OLNode* lstNode)
{
	if (lstNode->next == NULL)
		return 1;
	
	if (lstNode->dat < lstNode->next->dat)
		return recDefSort(lstNode->next);
	
	return 0;
}

//=============================================================
//=========================Main================================
//=============================================================
int main(int argc, char const *argv[])
{
	//*********************************************************
	const char *btks = "()[]{}";
	Options *arrOpt[64];
	initBtkCheck(arrOpt, btks);				// Packing brackets into a struct
	
	Stack *stack = initStack();				// Enter example in stack
	char entr;
	printf("Enter example:\n");
	do {
		scanf("%c", &entr);
		push(stack, entr);
	} while (entr != '\n');

	corrExp(stack, arrOpt);					// Base func

	int i = 0;								// Result output
	while (arrOpt[i] != NULL) {				
		printf("Brackets %c%c are %s\n", arrOpt[i]->sym1, arrOpt[i]->sym2, 
			(arrOpt[i]->point == 0) ? "correct" : "missing!!!");
		i++;
	}

	//*********************************************************
	OLList *lstFirst = (OLList*) malloc(sizeof(OLList));
	InitOLList(lstFirst);
	OLList *lstSecond = (OLList*) malloc(sizeof(OLList));
	InitOLList(lstSecond);

	for (int i = 0; i < 5; ++i) {
		InsertOLList(lstFirst, i * 2);
		InsertOLList(lstSecond, i * 3);
	}
	printf("List one: ");
	PrintOLList(lstFirst);
	printf("List two: ");
	PrintOLList(lstSecond);

	copyOLList(lstFirst, lstSecond);
	printf("List one after copy: ");
	PrintOLList(lstFirst);

	replaceOLList(lstFirst, lstSecond);
	printf("List one after replace: ");
	PrintOLList(lstFirst);

	//*********************************************************
	printf("List \"First\" is%s sorted\n", recDefSort(lstFirst->head) ? "" : " not");
	printf("List \"Second\" is%s sorted\n", recDefSort(lstSecond->head) ? "" : " not");


	return 0;
}