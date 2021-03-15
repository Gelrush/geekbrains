#include <iostream>
#include <cmath>
#include <cstdint>


namespace FirstHW 
{
    class Power
    {
    private:
        int x{ 1 };
        int y{ 1 };
    public:
        void setPower(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        int calculate()
        {
            return std::pow(x, y);
        }
    };
}

namespace SecondHW 
{
    class RGBA
    {
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;
    public:
        RGBA()
        {
            m_red = 0;
            m_green = 0;
            m_blue = 0;
            m_alpha = 255;
        }

        RGBA(int red, int green, int blue, int alpha)
            : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
        {
            if (red < 0 || red > 255)
                std::cerr << "Red formatted in " << (int) static_cast<uint8_t>(red) << std::endl;
            if (green < 0 || green > 255)
                std::cerr << "Red formatted in " << (int) static_cast<uint8_t>(green) << std::endl;
            if (blue < 0 || blue > 255)
                std::cerr << "Red formatted in " << (int) static_cast<uint8_t>(blue) << std::endl;
            if (alpha < 0 || alpha > 255)
                std::cerr << "Red formatted in " << (int) static_cast<uint8_t>(alpha) << std::endl;
        }

        void print()
        {
            std::cout << "Red[" << (int) m_red << "]; "
                << "Green[" << (int) m_green << "]; "
                << "Blue[" << (int) m_blue << "]; "
                << "Alpha[" << (int) m_alpha << "];" << std::endl;
        }
    };
}

namespace ThirdHW 
{
    constexpr int STACK_LEN{ 10 };

    class Stack
    {
    private:
        int arrElem[STACK_LEN]{};
        int size{ 0 };
    public:
        void reset()
        {
            size = 0;
            for (auto& elem : arrElem)
                elem = 0;
        }

        bool push(int elem)
        {
            if (size < STACK_LEN)
            {
                arrElem[size++] = elem;
                return true;
            }
            else
                return false;
        }

        int pop()
        {
            if (size > 0)
            {
                return arrElem[--size];     // нет смысла очищать ячейку
            }
            else
            {
                std::cerr << "Stack is empty!" << std::endl;
                return -1;
            }
        }

        void print()
        {
            std::cout << "( ";
            for (int i{ 0 }; i < size; ++i)
                std::cout << arrElem[i] << ' ';
            std::cout << ')' << std::endl;
        }
    };
}

int main()
{
    FirstHW::Power dot;
    std::cout << "Default 'Power' = " << dot.calculate() << std::endl;
    dot.setPower(5, 5);
    std::cout << "Mounted 'Power' = " << dot.calculate() << std::endl;
    puts("");

    SecondHW::RGBA pixel(125, 70, 99, 300);
    pixel.print();

    ThirdHW::Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    stack.pop();
}


