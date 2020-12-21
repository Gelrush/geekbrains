#include "func.h"

/*
	Сортировка "толстое" разбиение:
        рекурсивная сортировка, опорный элемент - последний
        поочередное сравнивание с двух сторон элементов с опорным
        если левый больше а правый меньше опорного, то меняются местами
        если равен то меняются с нулевым и предпоследним соответственно
        далее все равные опорному элементы перемещаются в середину
        и вызываются 2 рекурсии для левой и правой стороны
    Улучшенная быстрая сортировка:
        если в массиве меньше 10 элементов то Сортировка вставками
        если больше то определить среднее между первым, средним и последним
        элементом, передвинуть его в центр и использовать
        Сортировку Хоара - самый оптимальный вариант для любого случая
*/

void thickSplit(int* arr, int l, int r)
{
    int x = arr[r];
    if (r <= l) return;
    
    int i = l;
    int j = r - 1;
    int p = l - 1;
    int q = r;
    
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        
        if (i >= j) break;
        swapInt(&arr[i], &arr[j]);
        
        if (arr[i] == x)
            swapInt(&arr[++p], &arr[i++]);
        if (arr[j] == x)
            swapInt(&arr[--q], &arr[j--]);
    }
    swapInt(&arr[i], &arr[r]);
    j = i - 1;
    i++;
    
    for (int k = l; k <= p; ++k, --j)
        swapInt(&arr[k], &arr[i]);
    for (int k = r - 1; k >= q; ++k, ++i)
        swapInt(&arr[k], &arr[i]);
    
    thickSplit(arr, l, j);
    thickSplit(arr, i, r);
}

int main(int argc, char const *argv[])
{
	const int SIZE = 30;
	int arr[SIZE];
	fillIntRandom(arr, SIZE, 100);	
	printIntArray(arr, SIZE);	

    thickSplit(arr, 0, SIZE - 1);
    printIntArray(arr, SIZE);
	
	return 0;
}
