#include <iostream>
#include <string>

class Ex
{
protected:
    int x;
    int y;
    int route;

public:
    Ex(int erX, int erY, int l)
        : x(erX), y(erY), route(l)
    {   }

    virtual std::string what() const = 0;
};

class OffTheField : public Ex
{
public:
    OffTheField(int erX, int erY, int l)
        : Ex(erX, erY, l)
    {   }

    virtual std::string what() const
    {
        return "Error: Out of field. Position[" 
            + std::to_string(x) + "][" + std::to_string(y) + "]"
            + "-> command " + std::to_string(route);
    }
};

class IllegalCommand : public Ex
{
public:
    IllegalCommand(int erX, int erY, int l)
        : Ex(erX, erY, l)
    {   }

    virtual std::string what() const
    {
        return "Error: Bad route move. Command " + std::to_string(route) + " undefined";
    }
};

class Robot
{
private:
    std::string name;
    int x{ 0 };
    int y{ 0 };

public:
    Robot(std::string name)
        : name(name)
    {   }

    void move(int route)
    {
        switch (route)
        {
        case 8:     --y;    break;
        case 2:     ++y;    break;
        case 4:     --x;    break;
        case 6:     ++x;    break;
        default:    throw IllegalCommand(x, y, route);
        }

        if (x < 0 || x >= 10)
        {
            x = abs(x) - 1;
            throw OffTheField(x, y, route);
        }
        if (y < 0 || y >= 10)
        {
            y = abs(y) - 1;
            throw OffTheField(x, y, route);
        }
    }

    bool compare(int pX, int xY)
    {
        return (x == pX && y == xY);
    }
};

void printTable(Robot r)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if (!i || i == 11 || !j || j == 11)
                std::cout << " + ";
            else if (r.compare(j - 1, i - 1))
                std::cout << " R ";
            else std::cout << "   ";
        }
        puts("");
    }

}

int main(int argc, char const* argv[])
{
    Robot r("PL_3122");
    int route{ 1 };
    std::cout << "UP'8', DOWN'2', LEFT'4', RIGHT'6':\n";
    printTable(r);

    try
    {
        while (true)
        {
            std::cin >> route;
            r.move(route);

            printTable(r);
        }
    }
    catch (Ex& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
