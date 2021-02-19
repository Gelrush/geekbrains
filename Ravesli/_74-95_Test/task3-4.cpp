#include <iostream>

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
