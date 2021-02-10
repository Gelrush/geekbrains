#include <iostream>

int sumArray(int array[]) // array - это указатель
{
    int sum = 0;
    for (const auto& number : array) // ошибка компиляции, размер массива неизвестен
        sum += number;

    return sum;
}
int main() 
{   
    {
        int math[] = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 };
        for (auto number : math) // итерация по массиву math. тип number определяется автоматически исходя из типа элементов массива math
            std::cout << number << ' '; // получаем доступ к элементу массива в этой итерации через переменную number
    }
    {           // копирование может оказаться затратным
        int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
        for (auto &element : array) // символ амперсанда делает element ссылкой на текущий элемент массива, предотвращая копирование
            std::cout << element << ' ';
    }
    {
        int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
        for (const auto &element : array) // element - это константная ссылка на текущий элемент массива в итерации
            std::cout << element << ' ';
    }
    {       // foreach не работают с указателями (в том числе с динамическими массивами)
        int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
        std::cout << sumArray(array); // array распадается в указатель здесь
        return 0;
    }


    return 0;
}
