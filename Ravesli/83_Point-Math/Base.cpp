#include <iostream>

struct Man
{
    int weight;
    double height;
};

int main()
{   
    int value = 8;
    int* ptr = &value;

    std::cout << ptr << '\n'; // 002BFA20
    std::cout << ptr + 1 << '\n'; // 002BFA22
    std::cout << ptr + 2 << '\n'; // 002BFA24
    std::cout << ptr + 3 << '\n'; // 002BFA26

    int array[] = { 7, 8, 2, 4, 5 };
 
    std::cout << "Element 0 is at address: " << &array[0] << '\n'; // 002CF6F4
    std::cout << "Element 1 is at address: " << &array[1] << '\n'; // 002CF6F8
    std::cout << "Element 2 is at address: " << &array[2] << '\n'; // 002CF6FC
    std::cout << "Element 3 is at address: " << &array[3] << '\n'; // 002CF700

    {
    	int array [5] = { 7, 8, 2, 4, 5 };
 
     	std::cout << &array[1] << '\n'; // выведется адрес памяти элемента под индексом 1
     	std::cout << array+1 << '\n'; // выведется адрес памяти указателя на массив + 1 
 
     	std::cout << array[1] << '\n'; // выведется 8
     	std::cout << *(array+1) << '\n'; // выведется 8 (обратите внимание на скобки, они здесь обязательны)
    }

    {
    	const int arrayLength = 9;
		char name[arrayLength] = "Jonathan";
		int numVowels(0);
		for (char *ptr = name; ptr < name + arrayLength; ++ptr)
		{
			switch (*ptr)
			{
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				++numVowels;
			}
		}
 
		std::cout << name << " has " << numVowels << " vowels.\n";
    }

    {
    	Man man;

    	// Доступ к члену осуществляется через использование фактической переменной структуры Man
    	man.weight = 60;
    	// Доступ к члену осуществляется через ссылку на переменную структуры Man
    	Man& ref = man;
    	ref.weight = 60;
    	// Доступ к члену осуществляется через указатель на переменную структуры Man
    	Man* ptr = &man;
    	(*ptr).weight = 60; // идентичны
    	ptr->weight = 60; // идентичны
    }

    return 0;
}
