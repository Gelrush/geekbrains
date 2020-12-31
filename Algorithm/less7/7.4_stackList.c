#include <stdio.h>
#include <stdlib.h>

/*
	Список - базовая динамическая структура данных, 
		состоящая из узлов, каждый из которых содержит, 
		как собственно данные, так и одну или две ссылки 
		также называемые связками, на соседние узлы.
	Стэк - первым зашел, последним вышел.
*/

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

void init(Stack *stack) 
{
	stack->head = NULL;
	stack->size = 0;
}


boolean push(Stack *stack, T value)
{
	Node *tmp = (Node*) malloc(sizeof(Node));
	if (tmp == NULL) {							// Если в оперативной памяти не осталось места
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
		printf("Stack is empty\n");
		return -1;
	}
	Node *tmp = stack->head;
	T data = stack->head->dat;

	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}

void printOLStackNode(Node *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%c] ", n->dat);
}

void printOLStackList(Stack *stack) 
{
	Node *current = stack->head;
	if (current == NULL)
		printOLStackNode(current);
	else {
		do {
			printOLStackNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf("Size: %d \n", stack->size);
}

int main(int argc, char const *argv[])
{
	Stack *st = (Stack*) malloc(sizeof(Stack));
	init(st);
	push(st, 'a');
	push(st, 'b');
	push(st, 'c');
	push(st, 'd');
	
	printOLStackList(st);
	printf("%c <- deleted\n", pop(st));
	printOLStackList(st);
	printf("%c <- deleted\n", pop(st));
	printOLStackList(st);
	printf("%c <- deleted\n", pop(st));
	printOLStackList(st);
	printf("%c <- deleted\n", pop(st));
	printOLStackList(st);
	printf("%c <- deleted\n", pop(st));
	

	return 0;
}