#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // для exit()

// Аргументы командной строки
		// Доб: 200 "\"Hello world!\""

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Перебираем каждый аргумент и выводим его порядковый номер и значение
    for (int count = 0; count < argc; ++count)
        std::cout << count << " " << argv[count] << '\n';

	if (argc <= 1)
	{
		// В некоторых операционных системах argv[0] может быть просто пустой строкой, без имени программы

		// Обрабатываем случай, когда argv[0] может быть пустым или не пустым
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		exit(1);
	}
	{	// Конвертация из string в int
		std::stringstream convert(argv[1]); // создаем переменную stringstream с именем convert, инициализируя её значением argv[1]
		int myint;
		if (!(convert >> myint)) // выполняем конвертацию
			myint = 0; // если конвертация терпит неудачу, то присваиваем myint значение по умолчанию

		std::cout << "Got integer: " << myint << '\n';
	} /* std::stringstream работает почти так же, как и std::cin. Здесь мы инициализируем переменную std::stringstream значением argv[1], 
	так что мы можем использовать оператор >> для извлечения значения в переменную типа int.*/



    return 0;
}
