#include "func.h"

/*
	Хеширование; Хеш-функции

	Коллизии - это если при хешировании разных данных согласно хеш-таблице
		получается один и тот же хеш-код. В защищенных от коллизий алгоритмов
		коллизия это "расшифровка" данных.
	Хэширование с цепочками - при возникновении коллизии новый элемент 
		вставляется с список (массив) со своим порядковым номером 
		(создаются так называемые хеш-таблицы с прямым связыванием).
	Суммирование (метод хеширования) - создание расширенной хеш-таблицы с
		индексами которые получаются при суммировании номеров букв (по алфавиту) всего слова
	Возведение в степень - номер буквы умновается на число возможных букв в 
		степени порядкового номера данной буквы в слове

	Алгоритм MD5 - RFC 6151
		Этап 1. Добавление битов заполнения или выравнивания потока L=512*N+448
		Этап 2. Добавление длины сообщения. Добавляется 2 32-битных слова в конец сообщения.
		Этап 3. Инициализация буфера MD. Создаются 4 16-ричных слова типа unsined int.
		Этап 4. Обработка сообщения блоками по 16 слов. Принимает по 3 32-битных слова,
			в 4 раунда пропускает их черех логические функции пересчета, и выдает 1 слово,
			результаты раундов складываются.
		Этап 5. Вывод

	Хеш-таблицы - структура данных которая позволяет хранить пары (ключ, значение).
		Это самый обычный массив, каждый элемент это указатель на односвязный список.
		При выборе элемента массива для входящего числа (ключ) вычисляется процент 
			от деления количества элементов массива (наипростйший из способов создвния).

		Способы создания хеш-таблиц:
			Открытая адресация - в массиве хранятся сами пары ключ-значение.
			Закрытая адресация - используются 2 массива, один для ключей, второй для значений.

*/

typedef int K;			// выделение типа данных для хранения в хеш-таблице
typedef int htIndex;	// индекс внутри хеш-таблицы

int htSize;				// размер хеш-таблицы

htIndex hash(K data)
{
	return data % htSize;
}

boolean insertNode(OLNode** table, K data)
{
	OLNode *p, *p0;

	htIndex bucket = hash(data);
	p = (OLNode*) malloc(sizeof(OLNode));
	if (p == NULL) {
		printf("Out of memory! \n");
		return false;
	}
	p0 = table[bucket];
	table[bucket] = p;
	p->next = p0;
	p->dat = data;
	return true;
}

OLNode* findNode(OLNode** table, K data)
{
	OLNode *p = table[hash(data)];
	while (p && !(p->dat == data))
		p = p->next;
	return p;
}

void deleteNode(OLNode** table, K data)
{
	OLNode *parent, *current;
	parent = NULL;
	htIndex bucket = hash(data);
	current = table[bucket];
	while (current && !(current->dat == data)) {
		parent = current;
		current = current->next;
	}
	if (!current) {
		printf("Value not fount \n");
		return;
	}
	if (parent)
		parent->next = current->next;
	else
		table[bucket] = current->next;

	free(current);
}

void printTable(OLNode** table, int size)
{
	OLNode *p;
	for (int i = 0; i < size; ++i) {
		p = table[i];
		while (p) {
			printf("%5d", p->dat);
			p = p->next;
		}
		printf("\n");
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{
	htSize = 8;
	int* arr;
	const int SZ = 20;
	arr = (int*) malloc(sizeof(int) * SZ);
	fillIntRandom(arr, SZ, 100);

	OLNode** hashTable = (OLNode**) calloc(htSize, sizeof(OLNode*));
	for (int i = 0; i < SZ; ++i)
		insertNode(hashTable, arr[i]);
	printTable(hashTable, htSize);

	PrintOLNode(findNode(hashTable, 40));
	PrintOLNode(findNode(hashTable, 41));

	puts("");
	for (int i = 0; i < SZ / 2; ++i)
		deleteNode(hashTable, arr[i]);
	printTable(hashTable, htSize);

	return 0;
}