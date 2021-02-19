#include <iostream>

/*Перегрузка функций — это возможность определять несколько функций с одним и тем же именем, но с разными параметрами.*/

int subtract(int a, int b)
{   return a - b;   }
double subtract(double a, double b) 
{   return a - b;   }
int subtract(int a, int b, int c)
{   return a - b - c;   }

// Тип возврата функции НЕ учитывается при перегрузке функции
int getRandomValue();
double getRandomValue(); // ошибка компиляции!

void print(char* value);
void print(int value);

int main() 
{
    print(0); // точное совпадение с print(int)
    print('b'); // совпадение с print(int) после неявного преобразования
    

    return 0;
}
