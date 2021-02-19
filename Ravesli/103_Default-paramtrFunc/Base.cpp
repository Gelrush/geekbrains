#include <iostream>
#include "boo.h"

/*Параметр по умолчанию (или «необязательный параметр») — это параметр функции, 
который имеет определенное (по умолчанию) значение. Если пользователь не передает 
в функцию значение для параметра, то используется значение по умолчанию.*/

void printValues(int a, int b = 5)
{
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}
void printValues1(int a = 10, int b = 11, int с = 12)
{
    std::cout << "Values: " << a << " " << b << " " << c << '\n';
}

/*====================================================*/
    // Примеры применения
void openLogFile(std::string filename = "default.log");
int rollDie(int sides = 6);
void printStringInColor(std::string str, Color color = COLOR_RED); // Color - это перечисление


/*====================================================*/
    // Ошибки
void printValue2(int a = 5, int b); // не разрешается
void printValue3(int a, int b = 5); // верно!

void printValues4(int a, int b = 15); // параметр по умолчанию можно ставить при предварительном объявлении
void printValues4(int a, int b = 15) // ошибка: переопределение параметра по умолчанию. Параметр уже задан при предварительном объявлении!
{
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}

void printValues(int a);
void printValues(int a, int b = 15); // ошибка: параметры по умолчанию НЕ относятся к параметрам, которые учитываются при определении уникальности функции.

/*====================================================*/
void printValues5(int a, int b) // Правильно! Параметры по умолчанию указаны в предварительном объявлении в заголовочном файле
{
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
}

/*====================================================*/
    // Функции с параметрами по умолчанию могут быть перегружены.
void print(std::string string);
void print(char ch = ' ');


int main() 
{
    printValues(1); // в качестве b будет использоваться значение по умолчанию - 5
    printValues(6, 7); // в качестве b будет использоваться значение, предоставляемое пользователем - 7

    printValues1(3, 4, 5);
    printValues1(3, 4);
    printValues1(3);
    printValues1();

    printValues5(7);

    return 0;
}
