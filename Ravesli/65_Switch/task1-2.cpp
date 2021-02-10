#include <iostream>
#include <string>

int calculate(int x, int y, char op)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "calculate(): Unhandled case\n";
        return 0;
    }
}

enum Animal
{
    ANIMAL_PIG,
    ANIMAL_CHICKEN,
    ANIMAL_GOAT,
    ANIMAL_CAT,
    ANIMAL_DOG,
    ANIMAL_OSTRICH
};

std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
    case ANIMAL_CHICKEN:
        return "chicken";
    case ANIMAL_OSTRICH:
        return "ostrich";
    case ANIMAL_PIG:
        return "pig";
    case ANIMAL_GOAT:
        return "goat";
    case ANIMAL_CAT:
        return "cat";
    case ANIMAL_DOG:
        return "dog";

    default:
        return "getAnimalName(): Unhandled enumerator";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    switch (animal)
    {
    case ANIMAL_CHICKEN:
    case ANIMAL_OSTRICH:
        std::cout << "2";
        break;

    case ANIMAL_PIG:
    case ANIMAL_GOAT:
    case ANIMAL_CAT:
    case ANIMAL_DOG:
        std::cout << "4";
        break;

    default:
        std::cout << "printNumberOfLegs(): Unhandled enumerator";
        break;
    }

    std::cout << " legs.\n";
}

int main()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y;
    std::cin >> y;

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op;
    std::cin >> op;

    std::cout << x << " " << op << " " << y << " is " << calculate(x, y, op) << "\n";

    printNumberOfLegs(ANIMAL_CAT);
    printNumberOfLegs(ANIMAL_CHICKEN);

    return 0;
}
