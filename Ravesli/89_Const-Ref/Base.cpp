﻿#include <iostream>

void printIt(const int &a)
{
    std::cout << a;
}

int main() 
{   
    {
        const int value = 7;
        const int& ref = value; // ref - это ссылка на константную переменную value
    }
    {
        int a = 7;
        const int& ref1 = a; // ок: a - это неконстантное l-value

        const int b = 9;
        const int& ref2 = b; // ок: b - это константное l-value

        const int& ref3 = 5 + 3; // ок: 5 + 3 - это r-value
        std::cout << ref3; // область видимости r-value продлевается до конца блока

        a = 8; // ок: a - это не константа
    //    ref1 = 9; // нельзя: ref - это константа
    }
    {       // использование в функциях
        int x = 3;
        printIt(x); // неконстантное l-value

        const int y = 4;
        printIt(y); // константное l-value

        printIt(5); // литерал в качестве r-value

        printIt(3 + y); // выражение в качестве r-value
    }
    /*
    * Во избежание ненужного, слишком затратного копирования аргументов, переменные, которые не являются 
        фундаментальных типов данных (типов int, double и т.д.) или указателями, — должны передаваться по (константной) ссылке в функцию. 
        Фундаментальные типы данных должны передаваться по значению в случае, если функция не будет изменять их значений.
    */

    return 0;
}
