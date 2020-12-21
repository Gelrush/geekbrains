#include "func.h"

/*
    Сортировка слиянием:
        рекурсивно разбивается на массивы до 1 элемента
        после объединяется с другим массивом из 1 элемента
        в отсортированный ряд и так далее
 
*/

void merge(int* arr, int first, int mid, int last)
{
    int l = first;
    int r = mid + 1;
    int* tmp = (int*) malloc((last + 1) * sizeof(int));
    int step = 0;
    while (l <= mid && r <= last) {
        //printf("l - %d\n", arr[l]);
        //printf("arr[mid] - %d, mid - %d\n", arr[mid], mid);
        //printf("arr[r] - %d, r - %d\n", arr[r], r);
        //puts("");
        if (arr[l] < arr[r]) {
            tmp[step++] = arr[l++];
        }
        else {
            tmp[step++] = arr[r++];
        }
    }
    while (r <= last)
        tmp[step++] = arr[r++];
    while (l <= mid)
        tmp[step++] = arr[l++];
    
    for (int k = 0; k < last - first + 1; ++k) {
        //printf("tmp[k] - %d, k - %d, last - %d\n", arr[l], k, last);
        arr[first + k] = tmp[k];
    }
    //puts("");
}

void sortMerge(int* arr, int first, int last)
{
    int split;
    if (first < last) {
        split = (first + last) / 2;
        sortMerge(arr, first, split);
        sortMerge(arr, split + 1, last);
        merge(arr, first, split, last);
    }
}

int main(int argc, char const *argv[])
{
    const int SIZE = 14;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    printIntArray(arr, SIZE);

    sortMerge(arr, 0, SIZE);
    printIntArray(arr, SIZE);
    
    return 0;
}
