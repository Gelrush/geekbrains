﻿#include <iostream>
#include <array>

// Возврат значений по ссылке, по адресу и по значению

int doubleValue(int a)
{
    int value = a * 3;
    return value; // копия value возвращается здесь
} // value выходит из области видимости здесь

int* doubleValuePoint(int a)
{
    int value = a * 3;
    return &value; // value возвращается по адресу здесь
} // value уничтожается здесь

int* allocateArray(int size)
{
    return new int[size];
}

int& doubleValueLink(int a)
{
    int value = a * 3;
    return value; // value возвращается по ссылке здесь
} // value уничтожается здесь

int& getElement(std::array<int, 20>& array, int index)
{
    // Мы знаем, что array[index] не уничтожится, когда мы будем возвращать данные в caller (так как caller сам передал этот array в функцию!)
    // Так что здесь не должно быть никаких проблем с возвратом по ссылке 
    return array[index];
}

int returnByValue()
{
    return 7;
}

int& returnByReference()
{
    static int y = 7; // static гарантирует то, что переменная y не уничтожится, когда выйдет из локальной области видимости
    return y;
}

int main() 
{   
    {       // Возврат по значению
        int a = doubleValue(5);
        /* Когда не использовать возврат по значению:
        *   при возврате стандартных массивов или указателей (используйте возврат по адресу);
        *   при возврате больших структур или классов (используйте возврат по ссылке). */
    }
    {       // Возврат по адресу
        int* a = doubleValuePoint(5); // Ошибка! результатом будет то, что caller получит адрес освобожденной памяти (висячий указатель)

        int* array = allocateArray(20); // Возврат по адресу часто используется для возврата динамически выделенной памяти обратно в caller
        delete[] array;
        /*
            Когда использовать возврат по адресу:
   при возврате динамически выделенной памяти;
   при возврате аргументов функции, которые были переданы по адресу.
            Когда не использовать возврат по адресу:
   при возврате переменных, которые были объявлены внутри функции (используйте возврат по значению);
   при возврате большой структуры или класса, который был передан по ссылке (используйте возврат по ссылке).
        */
    }
    {       // Возврат по ссылке
        int a = doubleValueLink(5); // Ошибка! см. возврат по адресу

        std::array<int, 20> array;
        
        getElement(array, 15) = 7; // Присваиваем элементу массива под индексом 15 значение 7
        
        std::cout << array[15] << '\n';
        /*
            Когда использовать возврат по ссылке:
   при возврате ссылки-параметра;
   при возврате элемента массива, который был передан в функцию;
   при возврате большой структуры или класса, который не уничтожается в конце функции (например, тот, который был передан в функцию).
            Когда не использовать возврат по ссылке:
   при возврате переменных, которые были объявлены внутри функции (используйте возврат по значению);
   при возврате стандартного массива или значения указателя (используйте возврат по адресу).
        */
    }
    {           // ошибки
        int value = returnByReference(); // случай A: всё хорошо, обрабатывается как возврат по значению
            // мы присваиваем ссылку возвращаемого значения переменной, которая сама не является ссылкой. Возвращаемое значение просто копируется в value
    
    //  int& ref = returnByValue(); // случай B: ошибка компилятора, так как 7 - это r-value, а r-value не может быть привязано к неконстантной ссылке
        
        const int& cref = returnByValue(); // случай C: всё хорошо, время жизни возвращаемого значения продлевается в соответствии со временем жизни cref
                // но не имет смысла, возврат r-value нужно присваивать копированием значения
    }

    return 0;
}