#include <iostream>
#include <cstring>

int main()
{   
    char name[255]; // объявляем достаточно большой массив (для хранения 255 символов)
    std::cout << "Enter your name: ";
    std::cin.getline(name, 255); //cin.getline() будет принимать до 254 символов в массив name
    std::cout << "You entered: " << name << '\n';

    char text[] = "Print this!";
    char dest[50];
    strcpy_s(dest, text);
    std::cout << dest; // выводим "Print this!"

    char name[15] = "Max"; // используется только 4 символа (3 буквы + нуль-терминатор)
    std::cout << "My name is " << name << '\n';
    std::cout << name << " has " << strlen(name) << " letters.\n"; // реальное количество символов - 3
    std::cout << name << " has " << sizeof(name) << " characters in the array.\n"; // длина массива - 15
    /*
    *   функция strcat() — добавляет одну строку к другой(опасно);
    *   функция strncat() — добавляет одну строку к другой(с проверкой размера места назначения);
    *   функция strcmp() — сравнивает две строки(возвращает 0, если они равны);
    *   функция strncmp() — сравнивает две строки до определенного количества символов(возвращает 0, если до указанного символа не было различий).
    */

    return 0;
}
