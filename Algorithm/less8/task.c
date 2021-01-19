#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define T int
#define true 1 == 1			// сделать с помощью стека
#define false 1 != 1
typedef int boolean;

//==============================Supp func==============================
typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode **t, int data) 
{
	TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	TreeNode *current = *t;
	TreeNode *parent = *t;
	
	
	if (*t == NULL) {
		*t = newNode;
	} else {
		while (true) {	// current->key != data
			parent = current;
			if (current->key > data) {
				current = current->left;
				if (current == NULL) {
					parent->left = newNode;
					return *t;
				}
			} else {
				current = current->right;
				if (current == NULL) {
					parent->right = newNode;
					return *t;
				}
			}
		}
	}
	return *t;
}

void printTree(TreeNode *root)			
{
	if (root) {
		printf("%d", root->key);
		if (root->left || root->right) {
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

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

//==============================Task 1==============================
boolean result;
boolean checkBalance(TreeNode *root, int count, int max) 
{
	int x;
	if (root) {
		count++;
		if (root->left || root->right) {		
			if (root->left)
					result = checkBalance(root->left, count, max);
			else { 
				if (max - count > 1 || max - count < 0) 
					return false;
				count--;
			}
			
			if (root->right) 
					result = checkBalance(root->right, count--, max);
			else { 
				if (max - count > 1 || max - count < 0) 
					return false;
				count--;
			}
		}
		else { 
				if (max - count > 1 || max - count < 0) 
					return false;
				count--;
			}
	}
	return result;
}


boolean resultStack;

void chResult(int max, Stack* st)
{
	if (max - st->size > 1 || max - st->size < 0)
		resultStack = false;
	pop(st);
}

boolean checkBalanceStack(TreeNode *root, int max, Stack* st)
{
	if (root) {
		push(st, root->key);
		if (root-left || root-right) {
			if(root->left)
				checkBalanceStack(root-left, max, st);
			else chResult(max, st);

			if (root->right)
				checkBalanceStack(root-right, max, st);
			else chResult(max, st);
			
		} else chResult(max, st);
	}
}

TreeNode* fillRandTrees(int SZtree, int SZnode, int from, int to)
{
	TreeNode *tmpTree = NULL;
	for (int i = 0; i < SZnode; ++i) {
		treeInsert(&tmpTree, rand() % (to - from) + from);
	}
	return tmpTree;
}

//+++++++++++++++++++++++++++++++++__Answer teacher___+++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++____Non correct____+++++++++++++++++++++++++++++++++
int countDepth(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    int left = 0;
    int right = 0;
    if (node->left != NULL) {
        left = countDepth(node->left);
    }
    if (node->right != NULL) {
        right = countDepth(node->right);
    }
    return 1 + ((left > right) ? left : right);
}

boolean isBalanced(TreeNode *root) {
	printf("\nleft=%d, right=%d\n", countDepth(root->left), countDepth(root->right));
    return abs(countDepth(root->left) - countDepth(root->right)) <= 1;
}

//==============================Task 2==============================
boolean recBinSearch(TreeNode *root, int value) 	
{										
	if (root) {
		if (value == root->key) 
			return true;

		if (value < root->key)
			recBinSearch(root->left, value);
		else
			recBinSearch(root->right, value);

	} else return false;
}

int main(int argc, char const *argv[])
{
	//==============================Task 1==============================
	srand(time(NULL));
	const int SZtree = 50;
	const int SZnode = 5;
	TreeNode *tree[SZtree];
	int countBalance = 0;
	int maxNodes = (int) log2(SZnode) + 1;
	
	int countBalanceT = 0;

	for (int i = 0; i < SZtree; ++i) {
		tree[i] = fillRandTrees(SZtree, SZnode, 0, 100);
		result = true;
		countBalance += checkBalance(tree[i], 0, maxNodes);

		countBalanceT += isBalanced(tree[i]);
	}
	printf("==============================Task 1==============================\n");
	printf("Balanced %d%% of %d trees\n", countBalance * 100 / SZtree, SZtree);
	printf("From teacher. Balanced %d%% of %d trees\n", countBalanceT * 100 / SZtree, SZtree);
	
	//==============================Task 2==============================
	printf("==============================Task 2==============================\n");
	printTree(tree[0]);
	printf("\nNumber 15 is %sfound\n", recBinSearch(tree[0], 15) ? "" : "not ");

	printf("\n==============================Check solutions==============================\n");
	printf("My try. Balanced is %s\n", checkBalance(tree[0], 0, maxNodes) ? "true" : "false");
	printf("From teacher. Balanced is %s\n", isBalanced(tree[0]) ? "true" : "false");

	printf("==============================Test==============================\n");
	TreeNode *treetmp = NULL;
	treeInsert(&treetmp, 62);
	treeInsert(&treetmp, 30);
	treeInsert(&treetmp, 80);
	treeInsert(&treetmp, 79);
	treeInsert(&treetmp, 66);
	
	result = true;
	printTree(treetmp);
	puts("");
	printf("Balanced is %s\n", checkBalance(treetmp, 0, maxNodes) ? "true" : "false");

	printf("==============================Test Cycle==============================\n");
	for (int i = 0; i < SZtree; ++i)
	{
		treetmp = fillRandTrees(SZtree, SZnode, 0, 100);
		result = true;
		if (checkBalance(treetmp, 0, maxNodes)) {
			printTree(treetmp);
			puts("");
		}
	}



	return 0;
}