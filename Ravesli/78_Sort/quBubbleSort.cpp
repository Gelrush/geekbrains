#include <iostream>
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>

int quBubble(int* arr, const int len)
{
    int it;
    bool check;
    int lenAsort = len;

    for (it = 0; it < len - 1; it++)
    {
        check = true;
        lenAsort--;
        for (int idx = 0; idx < lenAsort; idx++)
        {
            if (arr[idx] > arr[idx + 1])
            {
                std::swap(arr[idx], arr[idx + 1]);
                check = false;
            }
        }
        if (check) break;
    }
    return it + 1;
}

void printArr(int* arr, const int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int main()
{   
    const int length(9);
    int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };

    std::cout << "Early termination on iteration: " << quBubble(array, length) << std::endl;
    printArr(array, length);


    return 0;
}
