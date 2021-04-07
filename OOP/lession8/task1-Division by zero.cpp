#include <iostream>

template<typename T>
T myDiv(T num, T den)
{
    if (den == 0) throw std::invalid_argument("Error: Division by zero!");

    return num / den;
}

int main(int argc, char const* argv[])
{
    int res{ 0 };

    try
    {
        res = myDiv(1, 0);
    }
    catch (std::invalid_argument e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "result = " << res << std::endl;


    return 0;
}
