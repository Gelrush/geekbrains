#include <iostream>

enum class COLORS
{
    RED,
    GREEN,
    BLACK,
    YELLOW,
    BLUE,
};

class Fruit
{
protected:
    std::string f_name;
    COLORS f_color;
public:
    Fruit(std::string name = "grapes", COLORS color = COLORS::BLACK)
        : f_name(name), f_color(color)
    {   }

    std::string getName() const { return f_name; }

    std::string getColor() const
    {
        switch (f_color)
        {
        case COLORS::RED:
            return "red";
        case COLORS::GREEN:
            return "green";
        case COLORS::BLACK:
            return "black";
        case COLORS::YELLOW:
            return "yellow";
        case COLORS::BLUE:
            return "blue";
        }
    }

    void setName(std::string name)
    {
        f_name = name;
    }

    void setColor(COLORS color)
    {
        f_color = color;
    }
};

class Apple : public Fruit
{
private:
    const std::string a_name;
public:
    Apple(COLORS color = COLORS::GREEN)
        : Fruit("apple", color), a_name("apple")
    {   }

    std::string getName() const
    {
        return a_name;
    }
};

class Banana : public Fruit
{
public:
    Banana(COLORS color = COLORS::YELLOW)
        : Fruit("banana", color)
    {   }

    std::string getName() const
    {
        return f_name;
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith(COLORS appleColor = COLORS::GREEN)
        : Apple(appleColor)
    {   }

    std::string getName()
    {
        return "Granny Smith " + f_name;
    }
};

int main(int argc, char *argv[])
{
    Apple a(COLORS::RED);
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


    return 0;
}
