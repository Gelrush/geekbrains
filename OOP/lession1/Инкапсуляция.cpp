#include <iostream>
#include <cassert>

/*
* Инкапсуляция (сокрытие информации) — это процесс скрытого хранения деталей реализации объекта. 
* В С++ инкапсуляция реализована с помощью спецификаторов доступа. 
* Инкапсулированные классы проще в применении и уменьшают сложность программ. 
* Один и тот же класс можно использовать в разных программах, при этом не заботиться о том, как устроен класс изнутри: 
* достаточно просто знать его методы. Также инкапсуляция защищает ваши данные и предотвращает неправильное использование
*/

struct DateStruct
{
    int day;
    int month;
    int year;
} today = { 12, 12, 2018 };

void print(DateStruct& date)
{
    std::cout << date.day << "/" << date.month << "/" << date.year;
}

class DateClass
{
public:
    int m_day;
    int m_month;
    int m_year;

    void printDate() // определяем функцию-член
    {
        std::cout << m_day << "/" << m_month << "/" << m_year;
    }
    void printYear();

};

// определяем функцию-член вне класса
void DateClass::printYear()
{
    std::cout << m_year << " year";
}


class Date
{
private:
    int m_day{ 1 };
    int m_month{ 1 };
    int m_year{ 2021 }; // по умолчанию
    const char* m_dayOfWeek; // День недели

public:
    Date() { std::cout << "Date\n"; }

    Date(int day, int month, const char* dayOfWeek = "mon")
        : m_day(day), m_month(month), m_dayOfWeek(dayOfWeek) // напрямую инициализируем переменные-члены класса
    {   /*поля инициализируются конструктором (значения по умолчанию выше не используются)*/  }


    int getDay() { return m_day; } // get-функция для day
    void setDay(int day) { m_day = day; } // set-функция для day

    int getMonth() { return m_month; } // get-функция для month
    void setMonth(int month) { m_month = month; } // set-функция для month

    const int& getYear() { return m_year; } // get-функция для year,возвращает значение по константной ссылке
    void setYear(int year) { m_year = year; } // set-функция для year
};

class Array
{
private:
    int* m_array;
    int m_length;

public:
    Array(int length) // конструктор
    {
        assert(length > 0);

        m_array = new int[length];
        m_length = length;
    }

    ~Array() // деструктор
    {
        // Динамически удаляем массив, который выделили ранее
        delete[] m_array;
    }
};

class Rectangle
{
public:
    static int m_square; // Статические переменные-члены класса
};
int Rectangle::m_square = 3;



int main(int argc, char *argv[])
{
    today.day = 18; // используем оператор выбора члена для выбора члена структуры
    print(today);

    DateClass today{ 12, 11, 2018 }; // объявляем переменную класса DateClass (поля public)
    today.m_day = 18;
    today.printDate();


    Rectangle first;
    Rectangle second;

    std::cout << first.m_square << '\n';
    first.m_square = 4;
    std::cout << second.m_square << '\n';

    return 0;
}
