#include <iostream>
#include <array>
#include <algorithm> // для std::sort

// std::array — это фиксированный массив, который не распадается в указатель при передаче в функцию.

void printLength(const std::array<double, 4> &myarray) // Всегда передавайте std::array в функции по обычной или по константной ссылке
{
    std::cout << "length: " << myarray.size() << std::endl;
    std::cout << "sizeof: " << sizeof(myarray) / sizeof(double) << std::endl;
}

template <typename Iter> // передача в функцию используя шаблоны с итерацией
void printStdArrayIter(Iter first, Iter last)
{
    for (; first != last; ++first)
        std::cout << *first << ' ';
}

template<std::size_t SIZE> // передача в функцию используя шаблоны
void printStdArrayTempl(std::array<int, SIZE>& arr) {
    for (auto &e : arr) {
        std::cout << e << ' ';
    }
}


int main() 
{   
    { // инициализация
        std::array<int, 4> myarray = { 8, 6, 4, 1 }; // список инициализаторов
        std::array<int, 4> myarray2{ 8, 6, 4, 1 }; // uniform-инициализация
    //  std::array<int, > myarray3 = { 8, 6, 4, 1 }; // нельзя, должна быть указана длина массива
        std::array<int, 4> myarray4;
        myarray4 = { 0, 1, 2, 3 }; // ок
        myarray4 = { 8, 6 }; // ок, элементам 2 и 3 присвоен нуль!
    //  myarray4 = { 0, 1, 3, 5, 7, 9 }; // нельзя, слишком много элементов в списке инициализаторов!
        std::array data{ 0, 1, 2, 3, 4, 5, 6 };  // если ваш компилятор поддерживает C++17

        // доступ к значениям
        std::cout << myarray[1] << std::endl;
        myarray[2] = 7;
        myarray.at(1) = 7; // элемент массива под номером 1 - корректный, присваиваем ему значение 7
    //  myarray.at(8) = 15; // элемент массива под номером 8 - некорректный, получим ошибку - исключение std::out_of_range
    }
    {
        std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };
        std::cout << "length: " << myarray.size() << std::endl; // выведет 4
        printLength(myarray); // выведет 4. Поскольку std::array не распадается в указатель при передаче в функцию
    }
    {       // фукнции
        std::array<int, 4> myarray{ 8, 6, 4, 1 };

        std::sort(myarray.begin(), myarray.end()); // сортировка массива по возрастанию
        std::sort(myarray.rbegin(), myarray.rend()); // сортировка массива по убыванию ( r - reverse )

        for (auto &element : myarray)
            std::cout << element << ' ';
        puts("");
        
        std::cout << typeid(myarray.begin()).name() << std::endl;

        printStdArrayIter(myarray.begin(), myarray.end());
        puts("");
        printStdArrayTempl(myarray);
    }
    {
    	std::array data{ 0, 1, 2, 3, 4, 5, 6 };
    }

    return 0;
}
