#include <stdio.h>
#include <stdlib.h>

/*
	Метод построения хеш-таблицы:
		Открытая адресация

	Каждый элемент массива таблицы будет содержать указатель 
		на структуру с данными ключ:значение

	Этап подготовки основных функций и создание простой хеш-таблицы.
*/

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
	p->key->data;
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
	for (i = 0; i < couhashTableSize / 2; ++i) 
		insertNode(oldHashTable[i]->data);
}

boolean insertNode(int data)
{
	KeyNode * node = createNode(data);
	if (!node) return false;

	int hashVal = hashFunc(node->key);
	if (isFull()) increaseCapacity();			// если ht переполнена то увеличить ее размер в 2 раза

	hashTable[hashVal] = node;
	return true;
}

KeyNode* findNode(int data)
{
	int key = data;
	int hashVal = hashFunc(key);

	if (hashTable[hashVal]->key == key) 
		return hashTable[hashVal];
	return NULL;
}

KeyNode* deleteNode(int data)
{
	int key = data;
	int hashVal = hashFunc(key);
	if (hashTable[hashVal]->key == key) {
		KeyNode *tmp = hashTable[hashVal];
		hashTable[hashVal] = nullItem;
		return temp;
	}
	return NULL;
}
 

int main(int argc, char const *argv[])
{
	hashTableSize = 25;				// создает ht
	hashTable = (KeyNode**) calloc(hashTableSize, sizeof(KeyNode*));
	nullItem = createNode(-1);

	return 0;
}