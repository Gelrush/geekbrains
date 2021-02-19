#include <iostream>

// Рекурсия
void countOut(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // условие завершения
        countOut(count - 1);

    std::cout << "pop " << count << '\n';
}

// Возвращаем сумму всех чисел между 1 и value
int sumCount(int value)
{
    if (value <= 0) return 0; // если изначально передано value <= 0
    
    if (value == 1) return 1; // базовый случай (условие завершения)
    
    return value + sumCount(value - 1); // рекурсивный вызов функции - 4 + (3 + (2 + (1)))
}

// Числа Фибоначчи
int fibonacci(int number)
{
    if (number == 0) return 0; // базовый случай (условие завершения)

    if (number == 1) return 1; // базовый случай (условие завершения)

    return fibonacci(number - 1) + fibonacci(number - 2);
}

int fibonacciIter(int number)
{
    int f1{ 1 }, f2{ 1 };

    if (!number) return 0;

    for (int i = 0; i < number - 2; ++i)
    {
        int tmp = f1 + f2;
        f1 = f2;
        f2 = tmp;
    }
    return f2;
}

int factorial(int num)
{
    if (num < 1) return 1;
    return num * factorial(num - 1);
}

int sumNumbers(int num)
{
    if (num < 10) return num;
    return num % 10 + sumNumbers(num / 10);
}

int main() 
{
    countOut(4);

    std::cout << "Summ number 4 = " << sumCount(4) << '\n';

    for (int count = 0; count < 13; ++count)
        std::cout << fibonacci(count) << " ";
    puts("");
    for (int count = 0; count < 13; ++count)
        std::cout << fibonacciIter(count) << " ";
    puts("");

    for (int i = 0; i < 6; ++i)
        std::cout << "Factoeial " << i << " = " << factorial(i) << std::endl;

    std::cout << "Sum of all numbers 482 = " << sumNumbers(482) << std::endl;
    

    return 0;
}
