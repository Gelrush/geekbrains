#include <iostream>

auto subtract(int a, int b) -> int; // синтаксис типа возвращаемого значения trailing в C++11

int main()
{
    /* автоматическим определением типа данных компилятором */
    auto x = 4.0; // 4.0 - это литерал типа double, поэтому и x должен быть типа double
    auto y = 3 + 4; // выражение 3 + 4 обрабатывается как целочисленное, поэтому и переменная y должна быть типа int

    auto result = subtract(4, 3); // функция subtract() возвращает значение типа int и, следовательно, переменная result также должна быть типа int
    std::cout << typeid(result).name() << " - " << result;

    return 0;
}

int subtract(int a, int b)
{
    return a - b;
}