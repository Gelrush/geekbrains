#include <iostream>

const char* getName()
{
    return "John";
}

int main()
{   
    {
        char myName[] = "John"; // можно изменять
        std::cout << myName;
    }
    {
        const char* myName = "John"; // только чтение, имеет статическую продолжительность жизни!!!
        std::cout << myName;
    }
    {
        const char* myName = getName();
        std::cout << myName;
    }
    {
        int nArray[5] = { 9, 7, 5, 3, 1 };
        char cArray[] = "Hello!";
        const char* name = "John";

        std::cout << nArray << '\n'; // nArray распадается в указатель типа int     - 0046FAE8
        std::cout << cArray << '\n'; // cArray распадается в указатель типа char    - Hello!
        std::cout << name << '\n'; // name уже и так является указателем типа char  - John
    }
    {
        char a = 'R';       // &a имеет тип char*, поэтому вместо адреса cout интепретирует "а" как строку 
        std::cout << &a;    // и выводит все символы до нуль-терминатора             
    }


    return 0;
}
