#include <iostream>

void printEven()
{
    for (int i = 0; i <= 20; i += 2)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int sumTo(int value)
{
    int sum = 0;
    for (int i = 1; i <= value; i++)
        sum += i;
    return sum;
}

int main()
{
    printEven();
    std::cout << "Sum = " << sumTo(5) << std::endl;

    return 0;
}
