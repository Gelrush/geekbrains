#include "func.h"

/*
	Граф - совокупность точек, соединенных линиями. 
		Точки называются вершинами, или узлами, а линии – ребрами, или дугами.
		Степень входа вершины – количество входящих в нее ребер, 
		степень выхода – количество исходящих ребер.

		Обход графа в ширину - проход ко всем доступным связям вершины графа,
			при этом запись смежных вершин послупает в очередь, когда
			доступные взяи закончатся, вытаскивание из очереди новой веришины 
			и проход по ее доступным связям.
*/

void clearVisited(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = 0;
}

void widthTravers(int** matrix, int start, const int size)
{
	TLList* queue = (TLList*) malloc(sizeof(TLList));	// очереди для хранения вершин для обработки
	InitTLList(queue);
	int visited[size];									// массив статуса посещаемости вершины
	clearVisited(visited, size);

	PushBTLList(queue, start);							// добавляем начальную вершину
	while (queue->size > 0){
		int idx = RmFTLList(queue)->dat;				// вытаскидвание вершины для ее обработки
		if (visited[idx] == 1) continue;				// если вершина посещалась, пропускаем ее
		visited[idx] = 1;
		printf("%d ", idx);

		for (int i = 0; i < size; ++i) {				// находим все не посещеннные для нее смежные вершины
			if ((get2dInt(matrix, idx, i) == 1) && visited[i] == 0)
				PushBTLList(queue, i);					// если связь имеется и вершина не помещалась
														// то положить вершину в очередь
		}
	}
}

/*int matrix[NUM][NUM] = {
	{0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0},
};*/

int main(int argc, char const *argv[])
{
	const int SZ = 6;
	int** adjacency = init2dIntArray(adjacency, SZ, SZ);
	set2dInt(adjacency, 0, 1, 1);
	set2dInt(adjacency, 0, 2, 1);
	set2dInt(adjacency, 1, 3, 1);
	set2dInt(adjacency, 1, 4, 1);
	set2dInt(adjacency, 1, 5, 1);
	set2dInt(adjacency, 2, 5, 1);
	set2dInt(adjacency, 3, 0, 1);
	set2dInt(adjacency, 5, 4, 1);

	widthTravers(adjacency, 0, SZ);
	puts("");
	widthTravers(adjacency, 3, SZ);
	puts("");
	widthTravers(adjacency, 1, SZ);
	puts("");

	return 0;
}