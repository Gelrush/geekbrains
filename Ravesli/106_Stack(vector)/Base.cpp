#include <iostream>
#include <vector>

/*std::vector в качестве стека*/


void printStack(const std::vector<int>& stack)
{
	for (const auto& element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main() 
{
	{
		std::vector<int> array;
		array = { 0, 1, 2, 3, 4, 5 }; // ок, длина array равна 6
		std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n'; // capacity - емкость (это количество выделенных элементов.);

		array = { 8, 7, 6, 5 }; // ок, длина array теперь равна 4!
		std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n'; // size - длина (количество фактически используемых элементов)
	}
	{
		std::vector<int> stack;

		stack.reserve(7); // устанавливаем ёмкость (как минимум), равную 7
		printStack(stack);

		stack.push_back(7); // функция push_back() добавляет элемент в стек
		printStack(stack);

		stack.push_back(4);
		printStack(stack);

		stack.push_back(1);
		printStack(stack);

		std::cout << "top: " << stack.back() << '\n'; // функция back() возвращает последний элемент
		std::cout << stack[0] << ' ' << stack.at(0) << '\n';

		stack.pop_back(); // функция pop_back() вытягивает элемент из стека
		printStack(stack);

		stack.pop_back();
		printStack(stack);

		stack.pop_back();
		printStack(stack);
	}
	{
		std::vector<int> vect = { 0, 1, 2, 3, 4, 5 };
		std::cout << "size: " << vect.size() << "  cap: " << vect.capacity() << '\n';

		vect.push_back(6); // добавляем другой элемент
		std::cout << "size: " << vect.size() << "  cap: " << vect.capacity() << '\n';
	}

    return 0;
}
