#include "func.h"

/*
    Сортировка подстчетом:
        сортировка для массивов в которых извесно 
        количество уникальных (положительных, натуальных) 
        элементов и оно относительно не большое
    Сортировка алгоритмом со списком:
        нахождение минимального и максимального элементов
        далее используется сортировка подсчетом
 
*/

void sortCounting(int* arr, int len, int max) // max - кол. уник. элементов
{
    int counts[max];
    for (int i = 0; i < max; ++i)
        counts[i] = 0;

    for (int i = 0; i < len; ++i)
        counts[arr[i]]++;

    int indx = 0;
    for (int i = 0; i < max; ++i)
        for (int j = 0; j < counts[i]; ++j) {
            arr[indx] = i;
            indx++;
        }
}

int findMin(int* arr, int len)
{
    int min = arr[0];
    for (int i = 0; i < len; ++i)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int findMax(int* arr, int len)
{
    int max = arr[0];
    for (int i = 0; i < len; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void sortPipeonhole(int* arr, int len)
{
    int min = findMin(arr, len);
    int max = findMax(arr, len);
    const int spread = abs(min) + abs(max) + 1; // для создания индекса отрицательных чисел
    int support[spread];
    for (int i = 0; i < spread; ++i) 
       support[i] = 0;

    for (int i = 0; i < len; ++i)
        support[arr[i] - min]++;
    
    int count = 0;
    for (int i = 0; i < spread; ++i)
        while (support[i] > 0) {
            arr[count++] = i + min;
            support[i]--;
        }
}

int main(int argc, char const *argv[])
{
    const int SIZE = 30;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 7);
    printIntArray(arr, SIZE);

    sortCounting(arr, SIZE, 7);
    printIntArray(arr, SIZE);

    puts("");
    fillIntRandom(arr, SIZE, 7);
    printIntArray(arr, SIZE);

    sortPipeonhole(arr, SIZE);
    printIntArray(arr, SIZE);

    
    return 0;
}
