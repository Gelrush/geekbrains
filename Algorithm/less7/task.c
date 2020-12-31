#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

const unsigned char option1 = 0x01; // шестнадцатеричный литерал для 0000 0001
const unsigned char option2 = 0x02; // шестнадцатеричный литерал для 0000 0010
const unsigned char option3 = 0x04; // шестнадцатеричный литерал для 0000 0100
const unsigned char option4 = 0x08; // шестнадцатеричный литерал для 0000 1000
const unsigned char option5 = 0x10; // шестнадцатеричный литерал для 0001 0000
const unsigned char option6 = 0x20; // шестнадцатеричный литерал для 0010 0000
const unsigned char option7 = 0x40; // шестнадцатеричный литерал для 0100 0000
const unsigned char option8 = 0x80; // шестнадцатеричный литерал для 1000 0000

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
		printf("");
		return;
	}
	printf("%c", n->dat);
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
	printf("\tSize: %d \n", stack->size);
}




typedef struct Options {
	char sym;
	unsigned char flags;
	unsigned char point;
} Options;

Options* initOpt(char sym)
{
	Options *opt = (Options*) malloc(sizeof(Options));

	opt->sym = sym;
	opt->flags = option1;
	opt->point = 0;

	return opt;
}


Options *btk1;
Options *btk2;
Options *btk3;







void corrExp(Stack *st)
{
	char tmp;
	while (true) {
		tmp = pop(st);
		if (tmp == -1) 
			return;

		
	}
}



int main(int argc, char const *argv[])
{
	Stack *stack = initStack();
	btk1 = initOpt('(');
	btk2 = initOpt('[');
	btk3 = initOpt('{');

	//char line[255] = "";
	char entr;
	do {
		scanf("%c", &entr);
		push(stack, entr);
	} while (entr != '\n');
	//printOLStackList(stack);
	
	corrExp(stack);


	


	//char *line = "[2/{5*(4+7)}]";
	//printf("%c\n", line[3]);
	return 0;
}