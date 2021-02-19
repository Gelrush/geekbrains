#include <iostream>


int getValue()
{
    int val;
    while (true)
    {
        std::cin >> val;

        if (std::cin.fail())
        {
            std::cout << "Uncorrect value! Try again.\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return val;
        }
    }
}

char getOperator()
{
    char ch;
    while (true)
    {
        std::cin >> ch;

        std::cin.ignore(32767, '\n');

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return ch;
        else
            std::cout << "Uncorrect operation! Try again.\n";
    }
}

int add(const int a, const int b) { return a + b; }
int subtract(const int a, const int b) { return a - b; }
int multiply(const int a, const int b) { return a * b; }
int divide(const int a, const int b) { return a / b; }

typedef int (*arithmeticFcn)(int, int);
arithmeticFcn getArithmeticFcn(char op)
{
    switch (op)
    {
    default: // функцией по умолчанию будет add()
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    
    }
    return nullptr;
}


/*=============================================*/
struct ArithmeticStruct
{
    char op;
    arithmeticFcn fnc;
};

static ArithmeticStruct arithmeticArray[]{
        {'+', add},
        {'-', subtract},
        { '*', multiply },
        { '/', divide }
};

arithmeticFcn getArithmeticFcn2(char op)
{
    for (auto &elem : arithmeticArray)
    {
        if (elem.op == op)
            return elem.fnc;
    }
    return add; // функцией по умолчанию будет add()
}


/*=============================================*/
typedef int (*mathFnc)(int, int);
int getArithmeticFcn3(int x, int y, mathFnc f = add)
{
    return f(x, y);
}

int main() 
{
    std::cout << "Enter first value: ";
    int x = getValue();
    std::cout << "Enter math operation: ";
    char op = getOperator();
    std::cout << "Enter second value: ";
    int y = getValue();

    std::cout << x << op << y << '=' << getArithmeticFcn(op)(x, y) << std::endl;

    std::cout << x << op << y << '=' << getArithmeticFcn2(op)(x, y) << std::endl;

    std::cout << x << op << y << '=' << getArithmeticFcn3(x, y) << std::endl; // параметр по умолчанию '+'
    std::cout << x << op << y << '=' << getArithmeticFcn3(x, y, getArithmeticFcn(op)) << std::endl;
    

    return 0;
}
