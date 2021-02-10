#include <iostream>

void incrementAndPrint()
{
    static int s_value = 1; // переменная s_value является статической
    ++s_value;
    std::cout << s_value << std::endl;
} // переменная s_value не уничтожается здесь, но становится недоступной

int generateID()
{
    static int s_itemID = 0;
    return s_itemID++;
}

int main()
{
    std::cout << "Hello World!\n";
    incrementAndPrint(); // вывод 2
    incrementAndPrint(); // вывод 3
    incrementAndPrint(); // вывод 4

    std::cout << generateID() << std::endl; // вывод 0
    std::cout << generateID() << std::endl; // вывод 1
    std::cout << generateID() << std::endl; // вывод 2

    return 0;
}