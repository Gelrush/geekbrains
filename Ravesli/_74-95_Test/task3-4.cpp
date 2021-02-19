<<<<<<< HEAD
﻿#include <iostream>

void swapInt(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void printStrCStyle(const char* str)
{
    for (; *str != 0; str++)
        std::cout << *str << ' ';
}

int main() 
{   
    int x = 5, y = 10;
    std::cout << x << ' ' << y << std::endl;
    swapInt(x, y);
    std::cout << x << ' ' << y << std::endl;

    printStrCStyle("Hello World!");

    return 0;
}
=======
﻿#include <iostream>

void swapInt(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void printStrCStyle(const char* str)
{
    for (; *str != 0; str++)
        std::cout << *str << ' ';
}

int main() 
{   
    int x = 5, y = 10;
    std::cout << x << ' ' << y << std::endl;
    swapInt(x, y);
    std::cout << x << ' ' << y << std::endl;

    printStrCStyle("Hello World!");

    return 0;
}
>>>>>>> cd5f4ed8b4ea1fd1b8e9469926f22436e96790fd
