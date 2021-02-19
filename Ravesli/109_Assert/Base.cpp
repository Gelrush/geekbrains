#include <iostream>
#include <array>
#include <cassert> // для assert()

/*Стейтмент assert (или «оператор проверочного утверждения») в языке C++ — это макрос препроцессора, который обрабатывает условное выражение во время выполнения. 
Если условное выражение истинно, то стейтмент assert ничего не делает. Если же оно ложное, то выводится сообщение об ошибке, и программа завершается.*/

    // Данная дериктива включется в релизной версии проекта
#define NDEBUG // !!! Все стейтменты assert будут проигнорированы аж до самого конца этого файла

int getArrayValue(const std::array<int, 10>& array, int index)
{
    // Предполагается, что значение index-а находится между 0 и 8
    assert(index >= 0 && index <= 8); // это строка 6 в Program.cpp
            // Assertion failed: index >= 0 && index <=8, file Base.cpp, line 10
    return array[index];
}

void getAnimal(char *found)
{
    assert(found); // при срабатывании выведет ошибку, но информации о ней никакой. если found примет значение false
    assert(found && "Animal could not be found in database"); // лучше! если assert сработает, то строка C-style будет включена в сообщение assert:
}

static_assert(sizeof(long) == 8, "long must be 8 bytes"); // срабатывает во время компиляции, вызывая ошибку компилятора
static_assert(sizeof(int) == 4, "int must be 4 bytes");

int main() 
{
    


    return 0;
}
