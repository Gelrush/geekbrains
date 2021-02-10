#include <iostream>

void printAlph()
{
    char sym = 'a';
    while (sym <= 'z') 
    {
        std::cout << sym << "-" << static_cast<int>(sym) << "\n";
        sym++;
    }
}

void printInvertRectangle()
{
    int outer = 5;
    while (outer > 0)
    {
        int inner = outer;
        while (inner > 0)
            std::cout << inner-- << " ";

        outer--;
        std::cout << std::endl;
    }
}

void printMirrorRectangle()
{
    int outer = 5;
    while (outer > 0)
    {
        int inner = outer - 1;
        while (inner > 0)
        {
            std::cout << "  ";
            inner--;
        }
        inner = 6 - outer;
        while (inner > 0)
        {
            std::cout << inner << " ";
            inner--;
        }
        outer--;
        std::cout << std::endl;
    }
}

void printMirrorRectangle1()
{
    int outer = 1;
    while (outer <= 5)
    {
        int inner = 5;
        while (inner > 0)
        {
            if (inner <= outer)
                std::cout << inner << " ";
            else
                std::cout << "  ";

            --inner;
        }
        std::cout << std::endl;
        ++outer;
    }
}

int main()
{
    printAlph();
    printInvertRectangle();
    printMirrorRectangle();
    printMirrorRectangle1();

    return 0;
}
