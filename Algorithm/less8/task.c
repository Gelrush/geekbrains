#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

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
		while (current->key != data) {
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


/*boolean checkBalance(TreeNode *root, int count) 
{
	if (root) {

		count++;

		if (root->left || root->right) {


			if (root->left) {
				checkBalance(root->left, count);
			} else {
				printf("%d-l\n", count);
				count--;
			}


			if (root->right) {
				checkBalance(root->right, count);
				count--;
			} else {
				printf("%d-r\n", count);
				count--;
			}


		} else {
			printf("%d-y\n", count);
			count--;
		}
	}
}*/

int maxNodes(TreeNode *root)
{
	if (root)
		return maxNodes(root->left) + 1;
	return 0;
}

boolean checkBalance(TreeNode *root, int max)
{
	int count = 0;
	TreeNode *current = root;
	TreeNode *parent = root;

	while (true) {
		parent = current;
		current = current->left;
		if (current == NULL) {
			current = parent->right;
		}
	}
}

/*boolean checkBalance(TreeNode *root, int count, int max) 
{
	int x;
	if (root) {
		count++;
		if (root->left || root->right) {

			if (root->left)
				checkBalance(root->left, count, max);
			else {
				x = abs(max - count--);
				printf("%d\n", x);
				if (x > 1) {
					printf("%d\n", x);
					return false;
				}
			}

			if (root->right) 
				checkBalance(root->right, count--, max);
			else {
				x = abs(max - count--);
				printf("%d\n", x);
				if (x > 1) {
					printf("%d\n", x);
					return false;
				}
			}

		} else {
				x = abs(max - count--);
				printf("%d\n", x);
				if (x > 1) {
					printf("%d\n", x);
					return false;
				}
			}
	}
	return true;
}*/

TreeNode* fillTrees(int SZtree, int SZnode)
{
	srand(time(NULL));
	TreeNode *tmpTree = NULL;

	for (int i = 0; i < SZnode; ++i) {
		treeInsert(&tmpTree, rand() % 100);
	}

	return tmpTree;
}


FILE *file;
TreeNode* balancedTree(int n) 			// n - количество узлов
{
	TreeNode *newNode;
	int x;
	int nL;
	int nR;

	if (n == 0) {
		return NULL;
	} else {
		fscanf(file, "%d", &x);			// считываем из файла данные
		nL = n / 2;						// при записывании нового узла 
		nR = n - nL - 1;				// рассчитывается равное количество потомков по 2м веткам

		newNode = (TreeNode*) malloc(sizeof(TreeNode));
		newNode->key = x;
		newNode->left = balancedTree(nL);
		newNode->right = balancedTree(nR);
	}
	return newNode;
}

int main(int argc, char const *argv[])
{
	const int SZtree = 50;
	const int SZnode = 15;
	TreeNode *tree[SZtree];
	int countBalance = 0;

	for (int i = 0; i < SZtree; ++i) {
		tree[i] = fillTrees(SZtree, SZnode);
		//if ()
	}


	int max = maxNodes(tree[0]);
	int result = 0;
	printf("Max = %d\n", max);
	printTree(tree[0]);
	puts("");
	printf("%s\n", checkBalance(tree[0], 0, max) ? "true" : "false");
	//checkBalance(tree[0], 0, max);

	
	file = fopen("balance.txt", "r");
	TreeNode *treeb = NULL;
	treeb = balancedTree(SZnode);
	printTree(treeb);
	puts("");
	max = maxNodes(treeb);
	printf("Max = %d\n", max);
	printf("%s\n", checkBalance(treeb, 0, max) ? "true" : "false");
	//checkBalance(treeb, 0, max);
	



	return 0;
}