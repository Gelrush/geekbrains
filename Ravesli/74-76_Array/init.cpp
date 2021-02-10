#include <iostream>

namespace StudentNames // для ошибок связанными с глобальным пространтвом имен
{
    enum StudentNames // Классы enum не имеют неявного преобразования в целочисленный тип
    {
        SMITH, // 0
        ANDREW, // 1
        IVAN, // 2
        JOHN, // 3
        ANTON, // 4
        MISHA, // 5
        MAX_STUDENTS // 6
    };
}

void printSize(int array[])
{
    std::cout << sizeof(array) << '\n'; // выводится размер указателя, а не массива - 4 байта
}

int main()
{   
    // Инициализируем все элементы массива значением 0
    int array[5] = { };

    int testScores[StudentNames::MAX_STUDENTS]; // всего 5 студентов
    testScores[StudentNames::JOHN] = 65; // с классами enum так не получится, нужно использовать static_cast

    int array[] = { 1, 3, 3, 4, 5, 9, 14, 17 };
    std::cout << sizeof(array) << '\n'; // выводится размер массива в байтах - 32
    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements\n";
    printSize(array); // 4

    return 0;
}
