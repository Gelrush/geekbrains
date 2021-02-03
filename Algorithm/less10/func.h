#ifndef FUNC_GB
#define FUNC_GB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OLNode {
	int dat;
	struct OLNode *next;
} OLNode;

typedef struct {
	OLNode *head;
	int size;
} OLList;

typedef struct TLNode {
	int dat;
	struct TLNode *next;
	struct TLNode *prev;
} TLNode;

typedef struct {
	TLNode *head;
	TLNode *tail;
	int size;
} TLList;

void swapInt(int *a, int *b);
void swapDbl(double *a, double *b);

int* initIntArray(const int len);
int** init2dIntArray(int** array, const int row, const int col);

void fillIntRandom(int* arr, const int len, int border);
void fill2dIntArray(int** array, const int row, const int col, int border);

void clearIntArray(int* arr, const int len);

void printIntArray(int* arr, const int len);
void print2dIntArray(int** array, const int row, const int col);

void sortIntBubble(int* arr, const int len);
void sortIntShaker(int* arr, const int len);
void sortIntInsert(int* arr, const int len);

int get2dInt(int** arr, int x, int y);
void set2dInt(int** arr, int x, int y, int dat);

/*
------------------------------------------------------------------------
-------------------------------One Link List----------------------------
------------------------------------------------------------------------
*/
void InitOLList(OLList* lst);
void InsertOLList(OLList *lst, int data);
OLNode* RmOLList(OLList *lst, int data);
void PrintOLNode(OLNode *n);
void PrintOLList(OLList *lst);
/*
------------------------------------------------------------------------
-------------------------------Two Link List----------------------------
------------------------------------------------------------------------
*/
void InitTLList(TLList* lst);
void PushFTLList(TLList *lst, int data);
void PushBTLList(TLList *lst, int data);
TLNode* RmFTLList(TLList *lst);
TLNode* RmBTLList(TLList *lst);
void PrintTLNode(TLNode *n);
void PrintTLList(TLList *lst); 






void swapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapDbl(double *a, double *b) 
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

int* initIntArray(const int len) 
{ 
	return (int*) calloc(sizeof(int), len); 
}

int** init2dIntArray(int** array, const int row, const int col)
{
	array = (int**) malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i)
		*(array + i) = (int*) calloc(sizeof(int*), col);
	return array;
}

void fillIntRandom(int* arr, const int len, int border)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
		*(arr + i) = rand() % border;
}

void fill2dIntArray(int** array, const int row, const int col, int border)
{
	srand(time(NULL));
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			*(*(array + i) + j) = rand() % border;
}

void clearIntArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i)
		arr[i] = 0;
}

void printIntArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%4d ", *(arr + i));
	puts("");
}

void print2dIntArray(int** array, const int row, const int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%4d ", *(*(array + i) + j));
		puts("");
	}
	puts("");
}

void sortIntBubble(int* arr, const int len)
{
	for (int j = 0; j < len; ++j)
		for (int i = 0; i < len - 1; ++i)
			if (arr[i] > arr [i + 1])
				swapInt(&arr[i], &arr[i + 1]);
}

void sortIntShaker(int* arr, const int len)
{
	int left = 1;
	int right = len - 1;
	while (left <= right) {
		int i;
		for (int i = right; i >= left; --i)
			if (arr[i - 1] > arr[i])
				swapInt(&arr[i], &arr[i - 1]);
		left++;
		for (int i = left; i <= right; ++i)
			if (arr[i - 1] > arr[i])
				swapInt(&arr[i], &arr[i - 1]);
		right--;
	}
}

void sortIntInsert(int* arr, const int len)
{
	int temp, pos;
	for (int i = 1; i < len; ++i) {
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

int get2dInt(int** arr, int x, int y)
{
	return arr[x][y];
}

void set2dInt(int** arr, int x, int y, int dat)
{
	arr[x][y] = dat;
}

/*
------------------------------------------------------------------------
-------------------------------One Link List----------------------------
------------------------------------------------------------------------
*/
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

/*
------------------------------------------------------------------------
-------------------------------Two Link List----------------------------
------------------------------------------------------------------------
*/
void InitTLList(TLList* lst) 
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void PushFTLList(TLList *lst, int data)
{
	TLNode *new = (TLNode*) malloc(sizeof(TLNode));
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

void PushBTLList(TLList *lst, int data)
{
	TLNode *new = (TLNode*) malloc(sizeof(TLNode));
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

TLNode* RmFTLList(TLList *lst)
{
	if (lst->head == NULL)
		return NULL;

	TLNode *tmp = lst->head;
	lst->head = lst->head->next;
	if (lst->head != NULL)
		lst->head->prev = NULL;

	if (tmp == lst->tail)		
		lst->tail = NULL;

	lst->size--;
	return tmp;
}

TLNode* RmBTLList(TLList *lst)
{
	if (lst->tail == NULL)
		return NULL;

	TLNode *tmp = lst->tail;
	lst->tail = lst->tail->prev;
	if (lst->tail != NULL)
		lst->tail->next = NULL;

	if (tmp == lst->head)	
		lst->head = NULL;

	lst->size--;
	return tmp;
}

void PrintTLNode(TLNode *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%d] ", n->dat);
}

void PrintTLList(TLList *lst) 
{
	TLNode *current = lst->head;
	if (current == NULL)
		PrintTLNode(current);
	else {
		do {
			PrintTLNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf("Size: %d \n", lst->size);
}


#endif