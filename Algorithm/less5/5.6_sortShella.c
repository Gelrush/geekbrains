#include "func.h"

/*
    Улучшенная сортировка вставками (сортировка Шелла):
        до нескольких тысяч элементов;
        массив делится пополам и сравниваются первые элементы каждого подмассива

*/

void sortShells(int* arr, int len)
{
    int i, j, step, temp;

    for (step = len / 2; step > 0; step /= 2)
        for (i = step; i < len; ++i) {
            temp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (temp < arr[j - step])
                    arr[j] = arr[j - step];
                else break;
            }
            arr[j] = temp;
        }
}


int main(int argc, char const *argv[])
{
    const int SIZE = 30;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    printIntArray(arr, SIZE);

    sortShells(arr, SIZE);
    printIntArray(arr, SIZE);

    
    return 0;
}
