#include <iostream>
#include <cstddef> // для std::nullptr_t

void doAnything(std::nullptr_t ptr)
{
    std::cout << "in doAnything()\n";
}

void doAnything(int* ptr)
{
    if (ptr)
        std::cout << "You passed in " << *ptr << '\n';
    else
        std::cout << "You passed in a null pointer\n";
}

int main()
{   
    int* ptr(0);  // ptr теперь нулевой указатель - NULL
    int* ptr1; // ptr1 не инициализирован
    ptr1 = 0; // ptr1 теперь нулевой указатель
    int* ptr2(NULL); // ptr2 теперь нулевой указатель
    int* ptr3 = nullptr; // C++11 ввели новое ключевое слово nullptr, которое избегает противоречий при присваивании значения "0" 

    // std::nullptr_t может иметь только одно значение — nullptr
    doAnything(nullptr); // вызов функции doAnything() с аргументом типа std::nullptr_t
    doAnything(ptr3); // вызов перегруженной функции 'int* ptr'


    return 0;
}
