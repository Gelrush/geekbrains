#include <iostream>

struct Rectangle
{
    int length;
    int width;
};

// Используем макрос-объект с текст_замена в качестве символьной константы
#define ARRAY_WIDTH 4
int array[ARRAY_WIDTH]; // синтаксически хорошо, но не делайте этого

// Используем символьную константу
const int arrayWidth = 7;
int array[arrayWidth]; // хорошо

// Используем перечислитель
enum ArrayElements
{   MIN_ARRAY_WIDTH = 3 };
int array[MIN_ARRAY_WIDTH]; // хорошо

int main()
{   
    Rectangle rects[4]; // объявляем массив с 4-мя прямоугольниками
    rects[0].length = 15;

    // Используем неконстантную переменную
    int width1;
    std::cin >> width1;
    int array[width1]; // плохо: width должна быть константой типа compile-time!

    // Используем константную переменную типа runtime
    int temp = 8;
    const int width2 = temp;
    int array[width2]; // плохо: здесь width является константой типа runtime, но должна быть константой типа compile-time!

    return 0;
}
