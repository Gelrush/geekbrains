#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// Эта функция сейчас нигде не вызывается, но находится здесь в случае, если вы захотите повторно провести тестирование
// Функция по автомотизации процесса тестирования функции isLowerVowel()
// Возвращается номер теста, который не был пройден или 0, если все тесты были пройдены успешно
int test()
{
    if (isLowerVowel('a') != true) return 1;
    if (isLowerVowel('q') != false) return 2;

    return 0;
}

int main()
{   
    

    return 0;
}
