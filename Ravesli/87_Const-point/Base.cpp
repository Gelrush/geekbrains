#include <iostream>

int main()
{   
    {
        const int c_value = 7;
        int* ptr1 = &c_value; // ошибка компиляции: невозможно конвертировать const int* в int*
        const int* ptr2 = &c_value; // здесь всё ок: ptr - это неконстантный! указатель, который указывает на "const int"
    }
    {
        int value = 7;
        const int* ptr = &value; // ptr указывает на "const int"
        value = 8; // переменная value уже не константа, если к ней получают доступ через неконстантный идентификатор
    }
    {
        int value = 7;
        const int* ptr = &value; // ptr указывает на "const int"
        *ptr = 8; // ptr обрабатывает value как константу, поэтому изменение значения переменной value через ptr не допускается
    }
    {
        int value1 = 7;
        const int* ptr = &value1; // ptr указывает на const int

        int value2 = 8;
        ptr = &value2; // хорошо, ptr теперь указывает на другой const int
    }    
    {               // Константные указатели
        int value1 = 7;
        int value2 = 8;

        int *const ptr = &value1; // ок: константный указатель инициализирован адресом value1
        ptr = &value2; // не ок: после инициализации константный указатель не может быть изменен

        *ptr = 10; // ок, так как ptr указывает на тип данных (неконстантный int)
    }
    {               // Константные указатели на константные значения
        int value = 7;
        const int* const ptr = &value; // ни значение ни указатель нельзя поменять
    }
    return 0;
}
