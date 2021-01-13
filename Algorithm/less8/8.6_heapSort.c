#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Бинарное дерево - количество потомков каждого узла не более 2х.
		Пирамидальная сортировка (сортировка кучей) - строится сбалансированное дерево,
			где каждая вершина меньше или равна своему родителю, то есть корень самое большое значение,
			далее меняем корень с самым удаленным листом и перестраиваем дерево, 
			корень отправляется в конец исходного массива. Процесс повторяется пока массив не заполнится.
				сложность постоянно O(N*log(N))
		Хранение дерева в массиве:
			arr[0] корень массива
			arr[2i+1] левый потомок i-ой вершины
			arr[2i+2] правый потомок i-ой вершины
		Условия пирамиды:
			arr[i] >= arr[2i+1]
			arr[i] >= arr[2i+2]
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

void buildTree(int* arr, int new, int size) {	// new - индекс добавляемого элемента
	int maxIdx = new;						// индекс максимального элемента из сравниваемых родителя и потомков
	int newElem = arr[new];					// значение добавляемого элемента

	while (true) {							
		int child = new * 2 + 1;			// высчитваем индекс левого потомка
		if ((child < size) && (arr[child] > newElem)) {
			maxIdx = child;					// если потомок больше своего родителя, то запишем его индекс 
		}	
		child = new * 2 + 2;				// тоже самое делает для правого потомка
		if ((child < size) && (arr[child] > arr[maxIdx])) {
			maxIdx = child;					
		}
		if (maxIdx == new)					// если оба потомка меньше, то выходим
			break;							
		arr[new] = arr[maxIdx];				// если один из потомков оказался больше, то меняем его с новым элементом
		arr[maxIdx] = newElem;
		new = maxIdx;						// что бы сравнить следующий элемент в новыми потомками (если появились)
	}
}

void heapSort (int* arr, int size) 
{
	for (int i = size / 2 - 1; i >= 0; --i) {
		buildTree(arr, i, size);			// построим дерево (за каждый вызов нужный лемент встает на нужное место)
	}

	while (size > 1) {
		--size;
		int firstElem = arr[0];
		arr[0] = arr[size];
		arr[size] = firstElem;
		buildTree(arr, 0, size);
	}
}



TreeNode* treeInsert(TreeNode *t, int data) 
{
	TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	TreeNode *current = t;
	TreeNode *parent = t;
	
	
	if (t == NULL) {							// если дерево пусто
		t = newNode;
	} else {
		while (current->key != data) {			// перемещаемся по дереву
			parent = current;
			if (current->key > data) {			// если значение узла больше добавляемого значения, то движемся влево
				current = current->left;
				if (current == NULL) {			// если предыдущий узел был листом, то добавляем ему наследника
					parent->left = newNode;
					return t;
				}
			} else {
				current = current->right;
				if (current == NULL) {			// делаем тоже самое для другой ветки
					parent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
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

void fillIntRandom(int* arr, const int len, int border)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
		*(arr + i) = rand() % border;
}

void printIntArray(int* arr, const int len)
{
	for (int i = 0; i < len; ++i) 
		printf("%4d ", *(arr + i));
	puts("");
}

int main(int argc, char const *argv[])
{
	const int SZ = 10;
	int arr[SZ];
	fillIntRandom(arr, SZ, 100);
	printIntArray(arr, SZ);
	heapSort(arr, SZ);
	printIntArray(arr, SZ);
	return 0;
}