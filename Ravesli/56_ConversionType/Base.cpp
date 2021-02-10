#include <iostream>
#include <iomanip> // для std::setprecision()
#include <typeinfo> // для typeid


int main()
{
    std::cout << "Hello World!\n";
    
    float f = 0.123456789; // значение типа double - 0.123456789 имеет 9 значащих цифр, но float может хранить только 7
    std::cout << std::setprecision(9) << f << std::endl;

    short x(3), y(6);
    std::cout << typeid(x + y).name() << " " << x + y << std::endl; // вычисляем решающий тип данных в выражении x + y

    std::cout << 5u - 10 << std::endl; // 5u означает значение 5 типа unsigned int
                          // вывод 4294967291
    char c = 97;
    std::cout << static_cast<int>(c) << std::endl; // в результате выведется 97, а не 'a'

    return 0;
}