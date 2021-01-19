#include <stdio.h>
#include <stdlib.h>

/*
	Бинарное дерево - количество потомков каждого узла не более 2х.
		Дерево поиска - 
*/

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
	
	
	if (*t == NULL) {							// если дерево пусто
		*t = newNode;
	} else {
		while (current->key != data) {			// перемещаемся по дереву
			parent = current;
			if (current->key > data) {			// если значение узла больше добавляемого значения, то движемся влево
				current = current->left;
				if (current == NULL) {			// если предыдущий узел был листом, то добавляем ему наследника
					parent->left = newNode;
					return *t;
				}
			} else {
				current = current->right;
				if (current == NULL) {			// делаем тоже самое для другой ветки
					parent->right = newNode;
					return *t;
				}
			}
		}
	}
	return *t;
}

void printTree(TreeNode *root)			// скобочная последовательность
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

TreeNode* getSuccessor(TreeNode *node) 
{
	TreeNode *current = node->right;
	TreeNode *parent = node;
	TreeNode *s = node; 				// наилучший на данный момент элемент

	while (current != NULL) {			// ищем самый маленький элемент (по левой стороне)
		parent = s;
		s = current;
		current = current->left;
	}
	if (s != node->right) {				// удаляем найденный элемент
		parent->left = s->right;		// при этом правый узел передаем родителю
		s->right = node->right;			// передать наденному узлу правую ссылку удаляемого изначально узла ???
	}
	return s;
}

boolean delete(TreeNode *root, int key)
{
	TreeNode *current = root;
	TreeNode *parent = root;
	boolean isLeftChild = true;

	while (current->key != key) {		// находим значение в дереве
		parent = current;
		if (key < current->key) {
			current = current->left;
			isLeftChild = true;
		} else {
			current = current->right;
			isLeftChild = false;
		}
		if (current == NULL)			// если значения нет, то выходим из функции
			return false;
	}

	if (current->left == NULL && current->right == NULL) { // если узел листовой
		if (current == root)			// и при этом является корнем
			root = NULL;
		else if (isLeftChild)			// удаляем ссылки у предка в зависимости от метки
			parent->left = NULL;		
		else
			parent->right = NULL;
	}
	else if (current->right == NULL) {	// если у удаляемого узла один потомок слева
		if (isLeftChild)				// то его потомка преносим родителю
			parent->left = current->left;
		else 
			parent->right = current->left;
	}
	else if (current->left == NULL) {	// если у удаляемого узла один потомок справа
		if (isLeftChild)
			parent->left = current->right;
		else
			parent->right = current->right;
	}									// при удалении узла с двумя наследниками нужно найти подходящий
	else {								// листовой узел и подставить его вместо удаляемого узла
		TreeNode *successor = getSuccessor(current);
		if (current == root)
			root = successor;
		else if (isLeftChild)
			parent->left = successor;
		else
			parent->right = successor;
		successor->left = current->left; // а тут уже передают лувую часть удаляемого найденному элементу.
	}
	return true;
}


void preOrderTravers(TreeNode *root) 	// прохождение всего дерева: Корень - левое - правое
{										// прямой обход - для копирования деревьев
	if (root) {
		printf("%2d ", root->key);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(TreeNode *root) 	// прохождение всего дерева: Левое - корень - правое
{										// центрированный обход - для обхода двоичное дерево 
	if (root) {							// 		поиска в порядке возрастания значения узлов
		inOrderTravers(root->left);
		printf("%2d ", root->key);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(TreeNode *root) 	// прохождение всего дерева: Левое - правый - корень
{										// обратный обход - для полного удаления дерева
	if (root) {
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%2d ", root->key);
	}
}


int main(int argc, char const *argv[])
{
	TreeNode *tree = NULL;
	treeInsert(&tree, 10);
	treeInsert(&tree, 8);
	treeInsert(&tree, 19);
	treeInsert(&tree, 5);
	treeInsert(&tree, 9);
	treeInsert(&tree, 16);
	treeInsert(&tree, 21);

	printTree(tree);
	printf("\n");

	preOrderTravers(tree);
	puts("");
	inOrderTravers(tree);
	puts("");
	postOrderTravers(tree);
	puts("");
	
	

	return 0;
}