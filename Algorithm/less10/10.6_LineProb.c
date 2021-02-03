#include <stdio.h>
#include <stdlib.h>

/*
	Метод построения хеш-таблицы:
		Открытая адресация

	Алгоритм хеш-функции:
		Линейное пробирование - если ячейка ht заполнена, 
			входные данные заполняются на следующую ячейку.
		Квадратичное пробирование - если ячейка ht заполнена,
			входные данные заполняются в значение ячейки + 
			расчет по геометрической прогрессии от количества шаков
		Двойное хеширование - шаг перехода расчитывается по формуле
			19 - key % 19;


*/

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct {
	int data;
	int key;
} KeyNode;

KeyNode** hashTable;				// хеш-таблица (далее ht)
int hashTableSize;

KeyNode *nullItem;					// идентификатор нулевого элемента в ht

int hashFunc(int key) 
{
	return key % hashTableSize;
}

KeyNode* createNode(int data)
{
	KeyNode *p = (KeyNode*) malloc(sizeof(KeyNode));
	if (!p) {
		printf("Out of memory \n");
		return NULL;
	}
	p->data = data;
	p->key = data;
	return p;
}

void initTable(int size, int idx) {
	for (int i = idx; i < size; ++i)
		hashTable[i] = NULL;
}



boolean isFull()
{
	for (int i = 0; i < hashTableSize; ++i)
		if (hashTable[i] == NULL || hashTable[i] == nullItem)
			return false;
	return true;
}

boolean insertNode(int data);
void increaseCapacity()
{
	hashTableSize *= 2;
	KeyNode** oldHashTable = hashTable;
	hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
	initTable(hashTableSize, 0);

	int i;
	for (i = 0; i < hashTableSize / 2; ++i) 
		insertNode(oldHashTable[i]->data);
}

int linearProbe(int val)
{
	++val;
	val %= hashTableSize;					// если val вышел за графицы массива, переносимся в начало
	return val;
}

int quadProbe(int val, int step) 
{
	val += step * step;
	val %= hashTableSize;
	return val;
}

int hashFuncDbl(int key)
{
	return 19 - key % 19;
}

boolean insertNode(int data)
{
	KeyNode * node = createNode(data);
	if (!node) return false;

	int hashVal = hashFunc(node->key);
	if (isFull()) increaseCapacity();		// если ht переполнена то увеличить ее размер в 2 раза

	int step = 0;
	//int step = hashFuncDbl(node->key);
	while (hashTable[hashVal] && hashTable[hashVal] != nullItem) {
		//hashVal = linearProbe(hashVal);			// линейное пробирование
		hashVal = quadProbe(hashVal, ++step);		// квадратичное пробирование
		//hashVal += step;							// двойное хеширование
		//hashVal %= hashTableSize;					// двойное хеширование
	}
	if (node->key == 15)
		printf("hashTable[%d] = %d\n", hashVal, node->key);
	hashTable[hashVal] = node;
	return true;
}

KeyNode* findNode(int data)
{
	int key = data;
	int hashVal = hashFunc(key);

	int step = 0;
	//int step = hashFuncDbl(key);
	while (hashTable[hashVal]) {			// поиск нужного узла линейным пробированием
		if (hashTable[hashVal]->key == key) 
			return hashTable[hashVal];
		//hashVal = linearProbe(hashVal);			// линейное пробирование
		hashVal = quadProbe(hashVal, ++step);		// квадратичное пробирование
		//hashVal += step;							// двойное хеширование
		//hashVal %= hashTableSize;					// двойное хеширование
	}
	return NULL;
}

KeyNode* deleteNode(int data)
{
	int key = data;
	int hashVal = hashFunc(key);

	int step = 0;
	//int step = hashFuncDbl(key);
	while (hashTable[hashVal]) {			// поиск нужного узла линейным пробированием
		if (hashTable[hashVal]->key == key) {
			KeyNode *tmp = hashTable[hashVal];
			hashTable[hashVal] = nullItem;
			return tmp;
		}
		//hashVal = linearProbe(hashVal);			// линейное пробирование
		hashVal = quadProbe(hashVal, ++step);		// квадратичное пробирование
		//hashVal += step;							// двойное хеширование
		//hashVal %= hashTableSize;					// двойное хеширование
	}
	return NULL;
}
 
void printNode(KeyNode *n)
{
	if (!n) {
		printf("[*,*]");
		return;
	}
	printf("[K=%d,d=%d]", n->key, n->data);
}

void printTbl() 
{
	for (int i = 0; i < hashTableSize; ++i)
		printNode(hashTable[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	hashTableSize = 15;				// создает ht
	hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
	nullItem = createNode(-1);

	insertNode(10);
	insertNode(10);
	insertNode(20);
	insertNode(30);
	insertNode(75);
	insertNode(57);
	insertNode(50);
	insertNode(60);
	insertNode(70);
	insertNode(100);
	insertNode(125);
	insertNode(1);
	insertNode(15);
	printTbl();

	deleteNode(10);
	deleteNode(20);
	printTbl();

	return 0;
}