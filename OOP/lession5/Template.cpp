#include <iostream>
#include <cassert>

        // Перегрузка операторов инкремента и декремента
class Day
{
private:
    int m_day;
public:
    Day(int day = 1) : m_day(day)
    { }
    Day& operator++();  // версия префикс
    Day& operator--();  // версия префикс

    Day operator++(int); // версия постфикс
    Day operator--(int); // версия постфикс

    void getDay() { std::cout << m_day << std::endl; }

    friend bool operator>(const Day& d1, const Day& d2);
};

Day& Day::operator++()      // версия префикс
{
    m_day = (m_day == 31) ? 1 : m_day + 1;
    return *this;
}
Day& Day::operator--()      // версия префикс
{
    m_day = (m_day == 1) ? 31 : m_day - 1;
    return *this;
}

Day Day::operator++(int)    // версия постфикс
{
    Day temp(m_day);
    ++(*this); // реализация перегрузки

    return temp;
}
Day Day::operator--(int)    // версия постфикс
{
    Day temp(m_day);
    --(*this); 
    return temp;
}


            // Шаблоны функций
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>   // для передачи в функцию в том числе и классов лучше использовать такой вариант
const T& t_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

bool operator>(const Day& d1, const Day& d2) // для классов необходима перегрузка операторов, дабы шаблон функции max работал
{
    return (d1.m_day > d2.m_day);
}



            // Шаблоны классов
template <class T> // шаблон класса
class Array
{
private:
    int m_length;
    T* m_data;

public:
    Array() { m_length = 0; m_data = nullptr; }
    Array(int length) { m_data = new T[length]; m_length = length; }
    ~Array() { delete[] m_data; }
    
    void Erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength(); // определяем метод и шаблон метода getLength() ниже
};

// метод, определенный вне тела класса, нуждается в собственном определении шаблона метода
template <typename T>
int Array<T>::getLength() { return m_length; }
// обратите внимание, имя класса - Array<T>, а не просто Array





template <class T, int size> // size является параметром non-type шаблона класса
class StaticArrayT
{
private:
    // параметр non-type шаблона класса отвечает за размер выделяемого массива
    T m_array[size];
    //  ...
};                       // объявление - StaticArray<int, 10>



                // Явная специализация шаблона функции
template <class T>
class Repository
{
private:
    T m_day;
public:
    Repository(T day) { m_day = day; }
    ~Repository() { }
    void print() { std::cout << m_day << '\n'; }
};

template <>         // Явная специализация при передаче указателя на char
Repository<char*>::Repository(char* day)
{
    // Определяем длину day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор

    // Выделяем память для хранения значения day
    m_day = new char[length];

    // Копируем фактическое значение day в m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}
template <>
Repository<char*>::~Repository()
{
    delete[] m_day;
}




// шаблон базового класса
template <class T, int size>
class StaticArray_Base
{
    // реализация класса StaticArray_Base
};

// шаблон производного класса
template <class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
    // полностью наследует функционал StaticArray_Base,
    // собственные методы не нужны
};

// частично специализированный шаблон класса для типа double
template <int size>
class StaticArray<double, size> : public StaticArray_Base<double, size>
{
    // реализация частично специализированного шаблона класса
};




                // Частичная специализация шаблонов и указатели
// Общий шаблон класса Day
template <class T>
class Days
{
private:
    T m_day;
public:
    Days(T day) { m_day = day; }
    ~Days() { }
    void print() { std::cout << m_day << '\n'; }
};

// частичная специализация шаблона класса Day для работы с типами указателей
template <typename T>
class Days<T*>
{
private:
    T* m_day;
public:
    Days(T* day) // T - тип указателя
    {
        // Выполняем глубокое копирование
        m_day = new T(*day); // здесь копируется только одно отдельное значение
    }
    ~Days()
    {
        delete m_day; // а здесь выполняется удаление этого значения
    }

    void print()
    {
        std::cout << *m_day << '\n';
    }
};

// Полная специализация шаблона конструктора класса Day для работы с типом char*
template <>
Days<char*>::Days(char* day)
{
    // Определяем длину day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор

    // Выделяем память для хранения значения day
    m_day = new char[length];

    // Копируем фактическое значение day в m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}

// Полная специализация шаблона деструктора класса Day для работы с типом char*
template<>
Days<char*>::~Days()
{
    delete[] m_day;
}

// Полная специализация шаблона метода print для работы с типом char*
// Без этого вывод Day<char*> привел бы к вызову Day<T*>::print(), которое выводит только одно значение (в случае со строкой C-style - только первый символ)
template<>
void Days<char*>::print()
{
    std::cout << m_day;
}


int main(int argc, char const* argv[])
{   
    Day day(31);
    day.getDay();
    (++day).getDay();
    (--day).getDay();

    (day++).getDay();
    (day).getDay();
    (day--).getDay();
    (day).getDay();




    int i = t_max(4, 8);
    std::cout << i << '\n';
    double d = t_max(7.56, 21.434);
    std::cout << d << '\n';
    char ch = t_max('b', '9');
    std::cout << ch << '\n';

    Day seven(7);
    Day twelve(12);
    Day bigger = t_max(seven, twelve);




    Array<int> intArray(10);
    Array<double> doubleArray(10);





    // Объявляем целочисленный объект для проверки работы общего шаблона класса
    Days<int> myDay(6);
    myDay.print();

    // Объявляем объект с типом указателя для проверки работы частичной специализации шаблона
    int x = 8;
    Days<int*> myintptr(&x);

    // Если бы в myintptr выполнилось поверхностное копирование (присваивание указателя),
    // то изменение значения x изменило бы и значение myintptr
    x = 10;
    myintptr.print();

    // Динамически выделяем временную строку
    char* fir = new char[40]{ "First" };

    // Сохраняем число
    Days<char*> myDay2(fir);

    // Удаляем временную переменную
    delete[] fir;

    // Выводим имя
    myDay2.print();

    return 0;
}
