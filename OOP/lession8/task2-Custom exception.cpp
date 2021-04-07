#include <iostream>

class Ex
{
public:
    int x;

    Ex(int num)
        : x(num)
    {   }
};

class Bar
{
private:
    int y{ 0 };

public:
    void setY(int a)
    {
        if (y + a > 100) throw Ex(y * a);

        y = a;
    }
};


int main(int argc, char const* argv[])
{
    Bar value;

    try
    {
        int num;
        do
        {
            std::cout << "waiting for input...\n";
            std::cin >> num;
            value.setY(num);
        } while (num);
    }
    catch (Ex& e)
    {
        std::cerr << "Error: Input result - " << e.x << '\n';
    }

    return 0;
}
