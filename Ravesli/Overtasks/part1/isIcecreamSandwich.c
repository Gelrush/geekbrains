#include <stdio.h>
#include <stdlib.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int bool;

typedef struct Node {
	T dat;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} Stack;

Stack* init() 
{
	Stack *stack = (Stack*) malloc(sizeof(Stack));
	stack->head = NULL;
	stack->size = 0;
	return stack;
}

bool push(Stack *stack, T value)
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

bool isIcecreamSandwich(char* str)
{
	if (str == NULL)
		return -1;

	Stack *sandwich = init();
	Stack *icecream = init();
	int flag;

	while (*str) {
		if (!sandwich->head || (flag == 0 && sandwich->head->dat == *str)) 
			flag = 0;
		else if (sandwich->head->dat != *str) 
			flag = 1;
		if (icecream->head && icecream->head->dat != *str) 
			flag = 2;

		if (flag == 0) 
			push(sandwich, *str);
		if (flag == 1)
			push(icecream, *str);
		if (flag == 2) 
			if (sandwich->head->dat != *str)
				return false;
			else pop(sandwich);

		str++;	
	}
	if (sandwich->size)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	char *IcecreamSandwich = "AAAARAAAA";
	printf("%s\n", isIcecreamSandwich(IcecreamSandwich) ? "true" : "false");
	return 0;
}