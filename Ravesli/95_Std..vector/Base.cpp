#include <iostream>
#include <vector>

/*
    std::vector (или просто «вектор») — это тот же динамический массив, но который может сам управлять выделенной себе памятью. 
    Это означает, что вы можете создавать массивы, длина которых задается во время выполнения, 
    без использования операторов new и delete (явного указания выделения и освобождения памяти).
*/

int main() 
{   
    {   // инициализация
        std::vector<int> array;
        std::vector<int> array2 = { 10, 8, 6, 4, 2, 1 }; // используется список инициализаторов для инициализации массива
        std::vector<int> array3{ 10, 8, 6, 4, 2, 1 }; // используется uniform-инициализация для инициализации массива (начиная с C++11)

        array = { 0, 2, 4, 5, 7 }; // ок, длина array теперь 5
        array = { 11, 9, 5 }; // ок, длина array теперь 3

        array[1] = 3; // без проверки диапазона 
        array.at(2) = 4; // с проверкой диапазона

        for (const auto &elem : array)
            std::cout << elem << ' ';
        puts("");
    }
    { // size() resize()
        std::vector<int> array{ 12, 10, 8, 6 };
        std::cout << "The length is: " << array.size() << '\n';

        array.resize(7); // изменяем длину array на 7 (можно и урезать)
        std::cout << "The length is: " << array.size() << '\n';

        for (const auto &element : array)
            std::cout << element << ' ';

    }

    return 0;
}
