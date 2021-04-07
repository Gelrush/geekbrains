#include <iostream>
#include <cmath>

/* Механизм исключительных ситуаций*/

double mySqrt(double a)
{
    // Если пользователь ввёл отрицательное число, то выбрасываем исключение
    if (a < 0.0)
        throw "Can not take sqrt of negative number"; // выбрасывается исключение типа const char*

    return sqrt(a);
}

class Parent        // Функциональный try-блок - для обработки исключений полученных из конструкторов родительских классов!!!
{
private:
    int m_age;
public:
    Parent(int age) : m_age(age)
    {
        if (age <= 0)
            throw 1;
    }
    virtual void print() { std::cout << "Parent"; }
};

class Child : public Parent
{
public:
    Child(int age) try : Parent(age) // обратите внимание на ключевое слово try здесь
    {   }
    catch (...) // Этот блок находится на том же уровне отступа, что и конструктор
    {
        // Исключения из списка инициализации членов класса Child или тела конструктора обрабатываются здесь

        std::cerr << "Construction of Parent failed\n";
        // Если мы здесь не будем явно выбрасывать исключение, то текущее (пойманное) исключение будет повторно сгенерировано и отправлено в стек вызовов
    }
    virtual void print() { std::cout << "Child"; }
};



int main(int argc, char const* argv[])
{
            // ТИПЫ ИСКЛЮЧЕНИЙ
    try
    {
        throw -1;      // генерация исключения типа int
        
        enum ER { ENUM_INVALID_INDEX };
        throw ENUM_INVALID_INDEX;       // генерация исключения типа enum

        throw "Cannot take square root of negative number"; // генерация исключения типа const char* (строка C-style)
        
        double dX;
        throw dX;   // генерация исключения типа double (переменная типа double, которая была определена ранее)
        
        class MyException : public std::exception { };
        throw MyException();   // генерация исключения с использованием объекта класса MyException
    }
    catch (int a)
    {
        std::cerr << "We caught an int exception with value" << a << '\n';
    }



            // РАСКРУЧИВАНИЕ СТЕКА
    double a = -1.1;
    try 
    {
        double d = mySqrt(a); // выбросит исключение
        std::cout << "The sqrt of " << a << " is " << d << '\n';
    }
    catch (const char* exception) // обработка исключений типа const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }

            // CATCH-ALL
    try
    {
        throw 7; // выбрасывается исключение типа int
    }
    catch (double a)
    {
        std::cerr << "We caught an exception of type double: " << a << '\n';
    }
    catch (...) // обработчик catch-all
    {   // Обработчик catch-all должен быть последним в цепочке блоков catch
        std::cerr << "We caught an exception of an undetermined type!\n";
    }


        
            // std::exception
    try
    {
        // Здесь код с использованием стандартной библиотеки С++
    }
    // Этот обработчик ловит bad_alloc и все дочерние ему классы-исключения
    catch (std::bad_alloc& exception)
    {
        std::cerr << "You ran out of memory!" << '\n';
    }
    // Этот обработчик ловит exception и все дочерние ему классы-исключения
    catch (std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }



                // Повторная генерация исключений
    try
    {
        try
        {
            throw Child(1);
        }
        catch (Parent& p)
        {
            std::cout << "Caught Parent p, which is actually a ";
            p.print();
            std::cout << "\n";
            throw; // Мы здесь повторно выбрасываем исключение
        }
    }
    catch (Parent& p)
    {
        std::cout << "Caught Parent p, which is actually a ";
        p.print();
        std::cout << "\n";
    }



                // Функциональный try-блок - для обработки исключений полученных из конструкторов родительских классов!!!
    try
    {
        Child child(0);
    }
    catch (int)
    {
        std::cout << "Oops!\n";
    }



    return 0;
}
