#include <iostream>
#include <algorithm>
#include <array>
#include <functional> // для std::greater{}

            /* Алгоритмы в Стандартной библиотеке С++ */

// Наша функция возвратит true, если элемент найден
bool containsNut(std::string_view str)
{
    // std::string_view::find возвращает std::string_view::npos, если он не нашел подстроку.
    // В противном случае, он возвращает индекс, где происходит вхождение подстроки в строку str
    return (str.find("nut") != std::string_view::npos);
}

bool greater(int a, int b)
{
    // Размещаем a перед b, если a больше, чем b
    return (a > b);
}

void doubleNumber(int &i)
{
    static int dInt = 1;
    dInt++;
    i *= dInt;
}

int main() 
{   
    {               // std::find
        std::array<int, 6> arr{ 13, 90, 99, 5, 40, 80 };

        std::cout << "Enter a value to search for and replace with: ";
        int search{};
        int replace{};
        std::cin >> search >> replace;

        // std::find() возвращает итератор, указывающий на найденный элемент (или на конец контейнера).
        // Мы сохраним его в переменной, используя автоматический вывод типа итератора
        auto found{ std::find(arr.begin(), arr.end(), search) };

        // Алгоритмы, которые не нашли то, что искали, возвращают итератор, указывающий на конец контейнера.
        if (found == arr.end())
            std::cout << "Could not find " << search << '\n';
        else
            *found = replace;   // Перезаписываем найденный элемент

        for (int i : arr)
            std::cout << i << ' ';
        puts("");
    }
    {               // std::find_if
        std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

        // Сканируем наш массив, чтобы посмотреть, содержат ли какие-либо элементы подстроку "nut"
        auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

        if (found == arr.end())
            std::cout << "No nuts\n";
        else
            std::cout << "Found " << *found << '\n';
    }
    {               // std::count() и std::count_if() ищут все вхождения элемента или элемента, соответствующий заданным критериям.
        std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

        auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };

        std::cout << "Counted " << nuts << " nut(s)\n"; // Counted 2 nut(s)
    }
    {               // std::sort() и пользовательская сортировка
        std::array arr{ 13, 90, 99, 5, 40, 80 };

        // Передаем greater в качестве аргумента в функцию std::sort()
        std::sort(arr.begin(), arr.end(), greater);
    //  std::sort(arr.begin(), arr.end(), std::greater{}); // используем greater из Стандартной библиотеки С++ для тех же целей
                // Фигурные скобки создают анонимный объект типа данных std::greater

        for (int i : arr)
            std::cout << i << ' '; // 99 90 80 40 13 5
        std::cout << '\n';
    }
    {               // std::for_each() - применяет пользовательскую функцию к каждому элементу этого списка
        std::array arr{ 1, 2, 3, 4, 5, 6 };

        std::for_each(arr.begin(), arr.end(), doubleNumber); // для удвоения всех чисел в массиве

        for (int i : arr)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    /*
    * Следующие алгоритмы гарантируют последовательное выполнение:
    * std::for_each()
    * std::copy()             std::copy_backward()
    * std::move()             std::move_backward()
    */


    return 0;
}
