#include <stdio.h>
#include <stdlib.h>

typedef struct OLNode {
	char dat;
	int count;
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

void InsertOLList(OLList *lst, char data)
{
	OLNode *new = (OLNode*) malloc(sizeof(OLNode));
	new->dat = data;
	new->count = 0;
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
		new->count = lst->size;
		current->next = new;
		lst->size++;
	}
}

OLNode* RmDOLList(OLList *lst, char data)		
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
	current->next->count = parent->count + 1;	
	lst->size--;
	return current;
}

OLNode* RmFOLList(OLList *lst)
{
	OLNode *tmp = lst->head;
	if (tmp == NULL)
		return NULL;

	lst->head = lst->head->next;
	OLNode *current = lst->head;
	lst->size--;
	return tmp;
}


void PrintOLNode(OLNode *n)
{
	if (n == NULL) {
		printf("[] ");
		return;
	}
	printf("[%d]-%d ", n->dat, n->count);
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




int checkBtk(char sym, const char *btks)
{
	int i = 0;
	while (btks[i] != '\0') {
		if (btks[i] == sym) return i;
		i++;
	}
	return -1;
}

void corrExp(OLList *lst, const char *btks)
{
	int i = 1;
	while (lst->head != NULL) {
		int idBtks = checkBtk(lst->head->dat, btks);
		int idNodeSym = lst->head->count;
		free(RmFOLList(lst));

		if (idBtks == -1) continue;
		if (idBtks % 2 == 1)
			printf("%d. Brackets %c are missing for %d index!\n", i++, btks[idBtks - 1], idNodeSym);
		else {
			if (RmDOLList(lst, btks[idBtks + 1]) == NULL) 
				printf("%d. Brackets %c are missing for %d index!\n", i++, btks[idBtks + 1], idNodeSym);
		}
	}
	if (i == 1)
		printf("Example is correct\n");
}




int main(int argc, char const *argv[])
{
	OLList *lst = (OLList*) malloc(sizeof(OLList));
	InitOLList(lst);				
	char entr;
	printf("Enter example:\n");
	do {
		scanf("%c", &entr);
		InsertOLList(lst, entr);
	} while (entr != '\n');

	const char *btks = "()[]{}";
	corrExp(lst, btks);

	return 0;
}