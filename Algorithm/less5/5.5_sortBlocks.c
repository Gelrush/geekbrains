#include "func.h"

/*
    Блочная сортировка:
        разбиение последовательности на блоки (корзины)
        сортировка каждого блока и соединение обратно
        считается очень быстрой сортировкой
*/

void sortBucket(int* arr, int len)
{
    const int max = len;
    const int b = 10; // количество корзин

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i)
        buckets[i][max] = 0;

    for (int digit = 1; digit < 1000000000; digit *= 10)
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;
            //int counter = buckets[d][max];
            //buckets[d][counter] = arr[i];
            //counter++;
            //buckets[d][max] = counter;
            // аналогичные записи
            buckets[d][buckets[d][max]++] = arr[i]; 
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j)
                arr[idx++] = buckets[i][j];
            buckets[i][max] = 0;
        }
}

int main(int argc, char const *argv[])
{
    const int SIZE = 30;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    printIntArray(arr, SIZE);

    sortBucket(arr, SIZE);
    printIntArray(arr, SIZE);

    
    return 0;
}
