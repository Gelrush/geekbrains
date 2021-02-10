#include <iostream>

// Указатель типа void — это специальный тип указателя, который может указывать на объекты любого типа данных!

enum Type
{
    INT,
    DOUBLE,
    CSTRING
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
    case INT:
        std::cout << *static_cast<int*>(ptr) << '\n'; // конвертируем в указатель типа int и выполняем разыменование
        break;
    case DOUBLE:
        std::cout << *static_cast<double*>(ptr) << '\n'; // конвертируем в указатель типа double и выполняем разыменование
        break;
    case CSTRING:
        std::cout << static_cast<char*>(ptr) << '\n'; // конвертируем в указатель типа char (без разыменования)
        // std::cout знает, что char* следует обрабатывать как строку C-style.
        // Если бы мы разыменовали результат (целое выражение), то тогда бы вывелся просто первый символ из массива букв, на который указывает ptr
        break;
    }
}

int main() 
{   
    {
        int nResult;
        float fResult;

        struct Something
        {
            int n;
            float f;
        };
        Something sResult;

        void* ptr;
        ptr = &nResult; // допустимо
        ptr = &fResult; // допустимо
        ptr = &sResult; // допустимо
        std::cout << typeid(ptr).name() << std::endl;
    }
    {
        int value = 7;
        void *voidPtr = &value;
        auto *autoPtr = &value; // в отличие от авто, который нельзя поменять после инициализации

    //  std::cout << *voidPtr << std::endl; // запрещено: нельзя разыменовать указатель типа void

        int* intPtr = static_cast<int*>(voidPtr); // однако, если мы конвертируем наш указатель типа void в указатель типа int,
        std::cout << *intPtr << std::endl; // то мы сможем его разыменовать, будто бы это обычный указатель
    }
    {       // пример инпользования
        int nValue = 7;
        double dValue = 9.3;
        char szValue[] = "Jackie";

        printValue(&nValue, INT);
        printValue(&dValue, DOUBLE);
        printValue(szValue, CSTRING);
    }
    {
        void* ptr = 0; // ptr - это указатель типа void, который сейчас является нулевым
        /*
        Хотя некоторые компиляторы позволяют удалять указатели типа void, которые указывают на динамически выделенную память, 
        делать это не рекомендуется, так как результаты могут быть неожиданными.
        */
    }


    return 0;
}
