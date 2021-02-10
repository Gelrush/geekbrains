#include <iostream>
#include <string>
#include <cmath> // для функции sqrt()


int main()
{
    double z;
tryAgain: // это лейбл
    std::cout << "Enter a non-negative number: ";
    std::cin >> z;

    if (z < 0.0)
        goto tryAgain; // а это оператор goto 
                       // Оператор goto и соответствующий лейбл должны находиться в одной и той же функции
                       // прыжок вперед недопустим

    std::cout << "The sqrt of " << z << " is " << sqrt(z) << std::endl;

    return 0;
}
