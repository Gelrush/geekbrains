#include <iostream>

int getValue()
{
    int num;
    while (true)
    {
        std::cin >> num;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear(); 
            std::cin.ignore(32767, '\n');
            std::cerr << "Uncorrect enter! Try again: ";
        }
        else
        {
            return num;
        }
    }
}

int main(int argc, char const* argv[])
{
    std::cout << "Enter a int value: ";
    int num = getValue();

    return 0;
}
