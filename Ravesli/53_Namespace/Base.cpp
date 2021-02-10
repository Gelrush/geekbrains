#include <iostream>
#include "doo.h"
#include "boo.h"
#include "add.h" // объявление namespace в нескольких местах

int doOperation(int a, int b)
{
	return a * b;
}

namespace Too {
	namespace Roo {
		const int g_x = 7;
	}
}

namespace Foo = Too::Roo; // Foo теперь считается как Too::Roo

int main()
{
    std::cout << "Hello World!\n";
    
	std::cout << Boo::doOperation(4, 5) << std::endl; // вывод 9
	std::cout << Doo::doOperation(4, 5) << std::endl; // вывод -1
	std::cout << ::doOperation(4, 5) << std::endl; // вывод 20

	std::cout << Doo::add(4, 5) << std::endl; // вывод 45 

	std::cout << Foo::g_x;

    return 0;
}