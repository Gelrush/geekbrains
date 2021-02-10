#include <iostream>
#include <string>
/*
* В случаях нахождения двух разных перечислениях в одной области видимости
* их сравнивание приведет к положительному результату
* Для решения этой проблемы были придуманы классы enum (перечислители с областью видимости)
*/
using namespace std;

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

int main()
{
    cout << "Hello World!\n";
    
    enum class Fruits // добавление "class" к enum определяет перечисление с ограниченной областью видимости, вместо стандартного "глобального" перечисления 
    {
        LEMON, // LEMON находится внутри той же области видимости, что и Fruits
        KIWI
    };

    enum class Colors
    {
        PINK, // PINK находится внутри той же области видимости, что и Colors
        GRAY
    };

    Fruits fruit = Fruits::LEMON; // примечание: LEMON напрямую не доступен, мы должны использовать Fruits::LEMON
    Colors color = Colors::PINK; // примечание: PINK напрямую не доступен, мы должны использовать Colors::PINK

    int lemon = Fruits::LEMON; // Ошибка!!! необходимо в таком случае static_cast<int>(Fruits::LEMON)
    int john = StudentNames::JOHN; // Хорошо!!! классы enum не преобразуются неявно

    if (fruit == color) // ошибка компиляции, поскольку компилятор не знает, как сравнивать разные типы: Fruits и Colors
        std::cout << "fruit and color are equal\n";
    else
        std::cout << "fruit and color are not equal\n";

    return 0;
}// Нет никакого смысла использовать обычные перечисления