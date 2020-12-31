#include <stdio.h>


/*
	Днамические структуры данных - 
				структуры, память для которых выделяется по мере заполнения данных
		Стек: документы в стопке, последним положил - первым вытащил
*/
#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean; // псевдоним типа int

int cursor = -1;
T Stack[SIZE];

boolean push(T data)
{
	if (cursor < SIZE) {
		Stack[++cursor] = data;
		return true;
	} else {
		printf("Stack overflow\n");
		return false;
	}
}

T pop() {
	if (cursor != -1) {
		return Stack[cursor--];
	} else {
		printf("Stack is empty\n");
		return -1;
	}
}



int main(int argc, char const *argv[])
{
	push('a');
	push('b');
	push('c');
	push('d');
	push('e');
	push('f');

	while (cursor != -1)
		printf("%c ", pop());
	pop();
	return 0;
}