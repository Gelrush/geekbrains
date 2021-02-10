#include <iostream>
#include <string>

using namespace std;

typedef double time1_t; // создать псевдоним для любого типа данных и использовать его вместо фактического имени типа
        // обычно добавляют _t

using time2_t = double; // в C++11 ввели новый улучшенный синтаксис, называется type alias
        // реашет проблемы разыменования переменных

int main()
{
    cout << "Hello World!\n";
    
    time1_t x = 1;
    time2_t y = 1;
    cout << ((x == y) ? "true" : "false") << endl; // true

    return 0;
}