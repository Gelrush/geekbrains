#include <iostream>
#include <functional> // для std::function<bool(int, int)> - в C++11

/*Указатели на функции*/
/*Указатели на функции полезны, прежде всего, когда вы хотите хранить функции в массиве (или в структуре) или когда вам нужно передать одну функцию в качестве аргумента другой функции.*/

//  Параметры по умолчанию не будут работать с функциями, вызванными через указатели на функции.

int boo()
{
    return 7;
}

int doo()
{
    return 8;
}

double zoo()
{
    return 10;
}

int moo(int a)
{
    return 9;
}


    // фукнция сортировки. Третьим параметром является пользовательский выбор выполнения сортировки
bool ascending(int a, int b);
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int) = ascending) // полезным будет установить дефолтный (по умолчанию) способ сравнения чисел
{
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        int bestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // СРАВНЕНИЕ ВЫПОЛНЯЕТСЯ ЗДЕСЬ
                bestIndex = currentIndex;
        
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// Вот функция сравнения, которая выполняет сортировку в порядке возрастания
bool ascending(int a, int b)
{
    return a > b; // меняем местами, если первый элемент больше второго
}

// Вот функция сравнения, которая выполняет сортировку в порядке убывания
bool descending(int a, int b)
{
    return a < b; // меняем местами, если второй элемент больше первого
}

bool evensFirst(int a, int b)
{
    // Если a - чётное число, а b - нечётное число, то a идет первым (никакого обмена местами не требуется)
    if ((a % 2 == 0) && !(b % 2 == 0))
        return false;

    // Если a - нечётное число, а b - чётное число, то b идет первым (здесь уже требуется обмен местами)
    if (!(a % 2 == 0) && (b % 2 == 0))
        return true;

    // В противном случае, сортируем в порядке возрастания
    return ascending(a, b);
}

void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

/*==========================================================*/
typedef bool (*validateFcn)(int, int);
using validateFcn = bool(*)(int, int); // или легче type alias

bool validate(int a, int b, bool (*fcnPtr)(int, int)); // фу, какой синтаксис
bool validate(int a, int b, validateFcn pfcn); // вот это другое дело

bool validate(int a, int b, std::function<bool(int, int)> fcn); // указываем указатель на функцию с помощью std::function, которая возвращает bool и принимает два int-а



int main() 
{
    std::cout << reinterpret_cast<void*>(boo) << std::endl; // указываем C++ конвертировать функцию boo() в указатель типа void

    int (*fcnPtr)() = boo; // fcnPtr указывает на функцию boo()
//    fcnPtr = doo(); // ошибка: присваиваем возвращаемое значение из вызова функции doo() указателю fcnPtr
    fcnPtr = doo; // fcnPtr теперь указывает на функцию doo()
//    fcnPtr = zoo; // не ок: тип указателя и тип возврата функции не совпадают!
//    fcnPtr = moo; // не ок: fcnPtr не имеет параметров, но moo() имеет
    int (*fcnPtr1)(int) = moo; // ок
    std::function<int()> fcnPtr2 = doo; // объявляем указатель на функцию, который возвращает int и не принимает никаких параметров

    (*fcnPtr1)(7); // вызываем функцию moo(7), используя fcnPtr. Явное разыменование
    fcnPtr1(7); // вызываем функцию moo(7), используя fcnPtr. Неявное зарыменование
    fcnPtr2(); // вызываем функцию doo(), используя fcnPtr2 с использованием стандартной библиотеки

    
    {       // Передача функций в качестве аргументов другим функциям по средствам указателя
        int array[8] = { 4, 8, 5, 6, 2, 3, 1, 7 };

        selectionSort(array, 8, descending); // Сортируем массив в порядке убывания, используя функцию descending()
        printArray(array, 8);

        selectionSort(array, 8, ascending); // Сортируем массив в порядке возрастания, используя функцию ascending()
        printArray(array, 8);

        selectionSort(array, 8, evensFirst); // Сортируем по возрастанию сначала четные числа, потом не четные, используя пользовательскую evensFirst()
        printArray(array, 8);

        selectionSort(array, 8); // Сортируем массив в порядке возрастания, используя параметр по умолчанию
        printArray(array, 8);
    }

    return 0;
}
