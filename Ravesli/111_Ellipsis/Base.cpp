#include <iostream>
#include <cstdarg> // требуется для использования эллипсиса
#include <string>
#include <initializer_list>


// Эллипсис должен быть последним параметром.
// Способ 1. Переменная count - это количество переданных аргументов
double findAverage1(int count, ...) 
{
    double sum = 0;

    // Мы получаем доступ к эллипсису через va_list, поэтому объявляем переменную этого типа
    va_list list;

    // Инициализируем va_list, используя va_start, его параметры:
    // Первый параметр - это список, который нужно инициализировать.
    // Второй параметр - это последний параметр, который не является эллипсисом (count)
    va_start(list, count);

    // Перебираем каждый из аргументов эллипсиса 
    for (int arg = 0; arg < count; ++arg)
    {
        // Используем va_arg для получения параметров из эллипсиса:
        // Первый параметр - это va_list, который мы используем.
        // Второй параметр - это ожидаемый тип параметров
        sum += va_arg(list, int); // с помощью va_arg() мы также переходим к следующему параметру va_list
    }

    // Выполняем очистку va_list, когда уже сделали всё необходимое 
    va_end(list);

    return sum / count;
}

// Способ 2. Эллипсис должен быть последним параметром
double findAverage2(int first, ...)
{
	// Обработка первого значения
	double sum = first;

    va_list list;
	va_start(list, first);

	int count = 1;
	while (true)
	{
		int arg = va_arg(list, int);

		// Если текущий параметр является контрольным значением, то прекращаем выполнение цикла
		if (arg == -1)
			break;

		sum += arg;
		count++;
	}

	// Выполняем очистку va_list, когда уже сделали всё необходимое
	va_end(list);

	return sum / count;
}

// Способ 3. Эллипсис должен быть последним параметром
double findAverage3(std::string decoder, ...)
{
    double sum = 0;
    va_list list;
    va_start(list, decoder);

    int count = 0;
    while (true)
    {
        char codetype = decoder[count];
        switch (codetype)
        {
        default:
        case '\0':
            // Выполняем очистку va_list, когда уже сделали всё необходимое
            va_end(list);
            return sum / count;

        case 'i':       // i = int
            sum += va_arg(list, int);
            count++;
            break;

        case 'd':       // d = double
            sum += va_arg(list, double);
            count++;
            break;
        }
    }
}

// Способ 4. Рекурсивный перебор с использованием вариадических шаблонов
template <typename T>
void func(T t) // перегрузка для последнего элемента
{
    std::cout << __FUNCSIG__ << ": " << typeid(t).name() << ' ' << t << std::endl;
}

template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << __FUNCSIG__ << ": " << typeid(t).name() << ' ' << t << std::endl;

    func(args...);
}

// Способ 5. Если все переменные аргументы имеют одинаковый тип - std::initializer_list 
template <class T>
void func2(std::initializer_list<T> list)
{
    for (auto &elem : list)
    {
        std::cout << typeid(elem).name() << ' ' << elem << std::endl;
    }
}

int main(int argc, char* argv[])
{
    {       // Способ 1
        std::cout << findAverage1(4, 1, 2, 3, 4) << '\n';
        std::cout << findAverage1(5, 1, 2, 3, 4, 5) << '\n';
    }
    {       // Эллипсис не безопасен
        int value = 8;
        std::cout << findAverage1(7, 1.0, 3, "Hello, world!", 'G', &value, &findAverage1) << '\n'; // Программа копилируется,но результат - мусор.
    }
    {       // Способ 2
        std::cout << findAverage2(1, 2, 3, 4, -1) << '\n';
        std::cout << findAverage2(1, 2, 3, 4, 5, -1) << '\n';
    }
    {       // Способ 3
        std::cout << findAverage3("iiii", 1, 2, 3, 4) << '\n';
        std::cout << findAverage3("iiiii", 1, 2, 3, 4, 5) << '\n';
        std::cout << findAverage3("ididdi", 1, 2.2, 3, 3.5, 4.5, 5) << '\n';
    }
    {       // Способ 4
        func(1, 2.5, 'a', "Hello");
    }     
    {       // Способ 5
        std::string str1("Hello"), str2("world");
        
        func2({ 10, 20, 30, 40 });
        func2({ str1, str2 });
    }

    return 0;
}
