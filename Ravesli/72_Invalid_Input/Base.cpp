#include <iostream>

double getValue() // Ошибка №2: Извлечение выполняется успешно, но пользователь вводит лишний текст
                  // Ошибка №3: Извлечение не выполняется
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a; // при вводе символа или переполненного значения - std::cin переходит в «режим отказа»

        if (std::cin.fail() || std::cin.peek() != '\n') // если предыдущее извлечение оказалось неудачным или за ним следовал другой символ
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо,
        {
            

            std::cin.ignore(32767, '\n'); // удаляем лишние значения
            return a; // и возвращаем число
        }
    }
}

char getOperator() // Ошибка №1: Извлечение выполняется успешно, но данные бесполезны
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;

        std::cin.ignore(32767, '\n'); // удаляем лишний балласт

        // Выполняем проверку значений
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/' || std::cin.peek() == '\n')
            return sm; // возвращаем данные в функцию main() 
        else // в противном случае, сообщаем пользователю, что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

void printResult(double a, char sm, double b)
{
    if (sm == '+')
        std::cout << a << " + " << b << " is " << a + b << '\n';
    else if (sm == '-')
        std::cout << a << " - " << b << " is " << a - b << '\n';
    else if (sm == '*')
        std::cout << a << " * " << b << " is " << a * b << '\n';
    else if (sm == '/')
        std::cout << a << " / " << b << " is " << a / b << '\n';
}

int main()
{   
    double a = getValue();
    char sm = getOperator();
    double b = getValue();

    printResult(a, sm, b);

    {
        std::int16_t x{ 0 }; // переменная x занимает 16 бит, её диапазон значений: от -32768 до 32767
        std::cout << "Enter a number between -32768 and 32767: ";
        std::cin >> x; // если ввести число более 32767, то std::cin перейден в «режим отказа»
    }

    return 0;
}
