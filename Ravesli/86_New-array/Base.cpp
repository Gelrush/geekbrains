#include <iostream>



int main()
{   
    int length;
    {
        std::cout << "Enter a positive integer: ";
        std::cin >> length;

        int* array = new int[length]; // используем оператор new[] для выделения массива. Обратите внимание, переменная length не обязательно должна быть константой!

        std::cout << "I just allocated an array of integers of length " << length << '\n';

        array[0] = 7; // присваиваем элементу под индексом 0 значение 7

        delete[] array; // используем оператор delete[] для освобождения выделенной массиву памяти
        array = 0; // используйте nullptr вместо 0 в C++11
    }
    {
        int* array1 = new int[length](); // инициализировать динамический массив значением 0
        int* array2 = new int[5]{ 9, 7, 5, 3, 1 }; // инициализируем динамический массив. Начиная с C++11

        int* dynamicArray1 = new int[] {1, 2, 3}; // не ок: неявное указание длины динамического массива
    }

    return 0;
}
