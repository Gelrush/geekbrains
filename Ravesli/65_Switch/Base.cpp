#include <iostream>
#include <cstdlib> // для функции exit()

enum class Colors
{
    GRAY,
    PINK,
    BLUE,
    PURPLE,
    RED
};

void printColor(Colors color)
{
	switch (color) // тип char, short, int, long, long long или enum
	{
	case Colors::GRAY: // либо литерал, либо перечисление, либо константа
		std::cout << "Gray";
		break;
	case Colors::PINK:
		std::cout << "Pink";
		break;
	case Colors::BLUE:
		std::cout << "Blue";
		break;
	case Colors::PURPLE:
		std::cout << "Purple";
		break;
	case Colors::RED:
		std::cout << "Red";
		break;
	default:
		std::cout << "Unknown";
		break;
	}
}

bool isDigit(char p)
{
    switch (p)
    {
    case '0': // если p = 0
    case '1': // или p = 1
    case '2': // или p = 2
    case '3': // или p = 3
    case '4': // или p = 5
    case '6': // или p = 6
    case '7': // или p = 7
    case '8': // или p = 8
    case '9': // или p = 9
        return true; // возвращаем true
    default: // в противном случае, возвращаем false
        return false;
    }
}

void block(int x)
{
    switch (x)
    {
    case 1: // не определяется новый блок
        int z; // ок, объявление разрешено
        z = 5; // ок, операция присваивания разрешена
        break;

    case 2:
        z = 6; // ок, переменная z была объявлена выше, поэтому мы можем использовать её здесь
        break;

    case 3:
        int c = 4; // нельзя, вы не можете инициализировать переменные внутри case
        break; // Это связано с тем, что инициализация переменной требует выполнения, а кейс, содержащий инициализацию, может никогда не выполниться!

    case 4:
    { // обратите внимание, здесь указан блок 
        int z = 5; // хорошо, переменные можно инициализировать внутри блока, который находится внутри кейса
        std::cout << z;
        break;
    }

    default:
        std::cout << "default case" << std::endl;
        break;
    }
}

int main()
{
	printColor(Colors::BLUE);


    exit(0); // завершаем выполнение программы и возвращаем 0 обратно в операционную систему
    return 0;
}