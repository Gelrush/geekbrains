#include <iostream>

void printSize(int* array)  // идентичнo void printSize(int array[]);
{
    // Здесь массив рассматривается как указатель 
    std::cout << sizeof(array) << '\n'; // выведется размер указателя, а не длина массива!
}

void changeArray(int* ptr)
{
    *ptr = 5; // поэтому изменение элемента массива приведет к изменению фактического массива
}

int main()
{   
    int array[] = { 2, 8, 6, 4, 9 };

    std::cout << sizeof(array) << '\n'; // выведется sizeof(int) * длина array - 20
    int* ptr = array;
    std::cout << sizeof(ptr) << '\n'; // выведется размер указателя - 4 (для x32 системы)

    {
        int val = 7;
        int* p = &val;

        std::cout << p << '\n'; // == &val
        std::cout << &val << '\n'; // == p
        std::cout << *p << '\n';
        std::cout << &p << '\n'; // адрес ячейки памяти выделенной для хранения адреса переменной val -> != &val
        std::cout << **&p << '\n'; // == val
    }

    printSize(array); // здесь аргумент array распадается на указатель

    std::cout << "Element 0 has value: " << array[0] << '\n';
    changeArray(array);
    std::cout << "Element 0 has value: " << array[0] << '\n';

    return 0;
}
