#include <iostream>
#include <string_view>
#include <iterator> // для функции std::size()
#include <string>

// класс std::string_view, который является нововведением стандарта С++17.
// класс std::string_view, по сути является переменной хранения ссылки на строковое значение, 
        // но преобразование (редактирвоание!!) изначальной строки через объект string_viewневозможно
// класс std::string спроектирован так, чтобы его объекты могли быть изменяемыми


std::string_view askForName()
{
    std::cout << "What's your name?\n";

    // Используем std::string, поскольку std::cin будет изменять строку
    std::string str{};
    std::cin >> str;

    // Мы переключаемся на std::string_view только в демонстрационных целях.
    // Если вы уже имеете std::string, то нет необходимости переключаться на std::string_view
    std::string_view view{ str };

    std::cout << "Hello " << view << '\n';

    return view;
} // str уничтожается и, таким образом, уничтожается и строка, созданная str

void print(std::string s)
{
    std::cout << s << '\n';
}

int main()
{   
    {
        std::string_view text{ "hello" }; // представление для строки "hello", которое хранится в бинарном виде
        std::string_view str1{ text }; // представление этой же строки - "hello"
        std::string_view more{ str1 }; // представление этой же строки - "hello"
    }

    {
        std::string_view str2{ "Trains are fast!" };

        std::cout << str2.length() << '\n'; // 16
        std::cout << str2.substr(0, str2.find(' ')) << '\n'; // Trains
        std::cout << (str2 == "Trains are fast!") << '\n'; // 1

        // Начиная с C++20
        std::cout << str2.starts_with("Boats") << '\n'; // 0
        std::cout << str2.ends_with("fast!") << '\n'; // 1
    }

    {
        char arr[]{ "Gold" };
        std::string_view str3{ arr };

        std::cout << str3 << '\n'; // Gold
        arr[3] = 'f'; // Изменяем 'd' на 'f' в arr
        std::cout << str3 << '\n'; // Golf
    }

       
    {
        std::string_view str4{ "Peach" };

        // Игнорируем первый символ
        str4.remove_prefix(1);
        std::cout << str4 << '\n'; // each

        // Игнорируем последние 2 символа
        str4.remove_suffix(2);
        std::cout << str4 << '\n'; // ea 
        // Изменив однажды область видимости, вы уже не сможете вернуться к первоначальным значениям
    }

    {
        // Нет нуль-терминатора
        char vowels[]{ 'a', 'e', 'i', 'o', 'u' };

        // Массив vowels не является нуль-терминированным. Мы должны передавать длину вручную.
        // Поскольку vowels является массивом, то мы можем использовать функцию std::size(), чтобы получить его длину
        std::string_view str5{ vowels, std::size(vowels) };

        std::cout << str5 << '\n'; // это безопасно, так как std::cout знает, как выводить std::string_view
                               // результат - aeiou
    }

    {
        std::string_view view{ askForName() };
        // view пытается обратиться к строке, которой уже не существует
        std::cout << "Your name is " << view << '\n'; // неопределенное поведение
    }

    // Конвертация std::string_view в std::string
    {
        std::string_view sv{ "balloon" };
        sv.remove_suffix(3);
        // print(sv); // ошибка компиляции: неявная конвертация запрещена
        std::string str{ sv }; // явное преобразование
        print(str); // ок
        print(static_cast<std::string>(sv)); // ок
    }


    // Конвертация std::string_view в строку C-style
    {
        std::string_view sv{ "balloon" };
        sv.remove_suffix(3);
        // Создание объекта std::string из объекта std::string_view
        std::string str{ sv };
        // Получаем строку C-style с нуль-терминатором
        auto szNullTerminated{ str.c_str() };
        // Передаем строку с нуль-терминатором в функцию, которую мы хотим использовать
        std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";
    }

    {
        std::string_view str{ "balloon" };
        std::cout << str << '\n';
        // Для простоты мы воспользуемся функцией std::strlen(). Вместо нее можно было бы использовать любую другую функцию, 
                // которая работает со строкой с нуль-терминатором в конце.
        // Здесь мы можем использовать функцию data(), так как мы не изменяли представление и строка имеет нуль-терминатор
        std::cout << std::strlen(str.data()) << '\n';

        str.remove_prefix(1); // Удаляем символ "b"
        str.remove_suffix(3); // Удаляем часть "oon"
        // Помните, что предыдущие 2 команды не изменяют исходную строку, они работают лишь с её представлением
        std::cout << str << " has " << std::strlen(str.data()) << " letter(s)\n"; // "all has 6 letter(s)"
        std::cout << "str.data() is " << str.data() << '\n'; // "str.data() is alloon"
        std::cout << "str is " << str << '\n'; // "str is all"
    }

    {
        std::string s{ "hello" };
        std::string_view v{ "world" };

        // Не работает
        std::cout << (s + v) << '\n';
        std::cout << (v + s) << '\n';

        // Потенциально небезопасно или не то, что мы хотим получить,
        // поскольку мы пытаемся использовать объект std::string_view в качестве строки C-style
        std::cout << (s + v.data()) << '\n';
        std::cout << (v.data() + s) << '\n';

        // Приемлемо, т.к. нам нужно создать новый объект std::string, но некрасиво и нерационально
        std::cout << (s + std::string{ v }) << '\n';
        std::cout << (std::string{ v } + s) << '\n';
        std::cout << (s + static_cast<std::string>(v)) << '\n';
        std::cout << (static_cast<std::string>(v) + s) << '\n';
    }

    return 0;
}
