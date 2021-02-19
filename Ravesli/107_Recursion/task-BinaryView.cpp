#include <iostream>

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

inline int getNumber()
{
    int num;
    while (true)
    {
        std::cin >> num;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Uncorrect enter! ";
        }
        else
            return num;
    }
}

void binaryView(unsigned num) // unsigned позволяет предтавлять отрицательные числа в двоичном виде
{
    if (num > 1)
        binaryView(num / 2);
    std::cout << num % 2;
}

int main() 
{
    for (int i = 0; i < 6; ++i)
        std::cout << "Factoeial " << i << " = " << factorial(i) << std::endl;

    std::cout << "Sum of all numbers 482 = " << sumNumbers(482) << std::endl;
    
    std::cout << "Enter number for binary view: ";
    int num = getNumber();
    std::cout << num << " = ";
    binaryView(num);


    return 0;
}
