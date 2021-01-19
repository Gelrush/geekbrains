#include <stdio.h>
#include <stdlib.h>


//==============================Supp func==============================
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
	int dat;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

void init(Stack *stack) 
{
	stack->head = NULL;
	stack->size = 0;
}

boolean push(Stack *stack, int value)
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

int pop(Stack *stack)
{
	if (stack->size == 0) {
		printf("Stack is empty\n");
		return -1;
	}
	Node *tmp = stack->head;
	int data = stack->head->dat;

	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}

int** init2dIntArray(int** array, const int row, const int col)
{
	array = (int**) malloc(sizeof(int*) * row);
	for (int i = 0; i < row; ++i)
		*(array + i) = (int*) calloc(sizeof(int*), col);
	return array;
}

int* initIntArray(const int len) 
{ 
	return (int*) calloc(sizeof(int), len); 
}

void printIntArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%d ", *(arr + i));
	puts("");
}

//==============================Task 1==============================				
void depthTravels(int** adj, const int SZ, int top)
{
	Stack *st = (Stack*) malloc(sizeof(Stack));
	int* visited = initIntArray(SZ);
	init(st);
	push(st, top);

	while (st->size > 0) {
		top = pop(st);
		if (top == -1) return;
		if (!visited[top])
			printf("%c ", top + 65);
		visited[top] = 1;
		for (int i = SZ; i > 0; --i) 	
			if (adj[top][i] == 1 && !visited[i]) 
				push(st, i);
	}
}

//==============================Task 2==============================
typedef struct Pair {
	char link;
	int count;
} Pair;

Pair** initPairArr(const int SZ)
{
	Pair** tmp = (Pair**) malloc(sizeof(Pair*) * SZ);
	for (int i = 0; i < SZ; ++i) {
		*(tmp + i) = (Pair*) malloc(sizeof(Pair));
		(*(tmp + i))->link = 65 + i;
		(*(tmp + i))->count = 0;
	}
	return tmp;
}

void printPair(Pair* p)
{
	printf("%c:%d ", p->link, p->count);
}

void printArrPair(Pair** p, const int SZ)
{
	for (int i = 0; i < SZ; ++i)
		printPair(*(p + i));
}

void swap(Pair* x, Pair* y)
{
	Pair* tmp = x;
	x = y;
	y = tmp;
}

void sortArrPair(Pair** p, const int len)
{
	for (int j = 0; j < len; ++j) {
		for (int i = 0; i < len - 1; ++i) {
			if ((*(p + i))->count > (*(p + i + 1))->count) {
				Pair* tmp = *(p + i);
				*(p + i) = *(p + i + 1);
				*(p + i + 1) = tmp;
			}				
		}
	}
}

void fillValue(int* arr, int count, int x, ...)
{
	int *tmp = &x;
	for (int i = 0; i < count; ++i) {
		arr[i] = *tmp;
		tmp++;
	}
}

void recTravels(int** adj, const int SZ, int start, Pair** conLink, int* visitedTop)
{
	int r;							
	visitedTop[start] = 1;
	for (r = 0; r < SZ; ++r) {		
		if (adj[start][r] == 1) {
			(*(conLink + r))->count++;
			if (!visitedTop[r])
				recTravels(adj, SZ, r, conLink, visitedTop);
		}
	}
}

void adjTravels(int** adj, const int SZ, Pair** conLink)
{
	for (int i = 0; i < SZ; ++i) {
		for (int j = 0; j < SZ; ++j) {
			if (adj[i][j] == 1)
				(*(conLink + j))->count++;
		}
	}
}



int main(int argc, char const *argv[])
{
	const int SZ = 14;
	int** adjacency = init2dIntArray(adjacency, SZ, SZ);
	fillValue(adjacency[0], SZ,  0,1,0,0,0,0,1,1,0,0,0,0,0,0);
	fillValue(adjacency[1], SZ,  1,0,1,0,0,0,1,0,0,0,1,0,0,0);
	fillValue(adjacency[2], SZ,  0,1,1,1,0,0,0,0,0,0,0,0,0,0);
	fillValue(adjacency[3], SZ,  0,0,1,0,0,0,0,0,0,1,0,0,0,1);
	fillValue(adjacency[4], SZ,  0,0,0,0,0,0,0,0,1,0,0,0,0,0);
	fillValue(adjacency[5], SZ,  0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	fillValue(adjacency[6], SZ,  1,1,0,0,0,0,0,0,0,0,1,1,0,0);
	fillValue(adjacency[7], SZ,  1,0,0,0,0,0,0,0,0,0,0,1,0,0);
	fillValue(adjacency[8], SZ,  0,0,0,0,1,0,0,0,1,0,0,0,0,0);
	fillValue(adjacency[9], SZ,  0,0,0,1,0,0,0,0,0,1,0,0,0,0);
	fillValue(adjacency[10], SZ, 0,1,0,0,0,0,1,0,0,0,0,1,1,0);
	fillValue(adjacency[11], SZ, 0,0,0,0,0,0,1,1,0,0,1,0,1,0);
	fillValue(adjacency[12], SZ, 0,0,0,0,0,0,0,0,0,0,1,1,0,1);
	fillValue(adjacency[13], SZ, 0,0,0,1,0,0,0,0,0,0,0,0,1,0);

	printf("==============================Task 1==============================\n");
	depthTravels(adjacency, SZ, 0);
	printf("\n==============================Task 2==============================\n");
	
	Pair** conLink_rec = initPairArr(SZ);
	recTravels(adjacency, SZ, 0, conLink_rec, initIntArray(SZ));
	sortArrPair(conLink_rec, SZ);
	
	Pair** conLink_adj = initPairArr(SZ);
	adjTravels(adjacency, SZ, conLink_adj);
	sortArrPair(conLink_adj, SZ);

	printf("================rec version================\n");
	printArrPair(conLink_rec, SZ);
	printf("\n================adj version================\n");
	printArrPair(conLink_adj, SZ);

	return 0;
}