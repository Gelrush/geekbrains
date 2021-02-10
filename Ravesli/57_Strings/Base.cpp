#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello World!\n";
    
    string name("Denis Frolov");
    cout << "My name is " << name << endl;

    std::cout << "Enter age ";
    int meAge;
    std::cin >> meAge;
    std::cin.ignore(32767, '\n'); // удаляем символ новой строки из входного потока данных

    string myName;
    getline(cin, myName); // полностью извлекаем строку в переменную myAge
    cout << "My name is " << myName << " and my age is " << meAge << endl;
    cout << "My name has " << myName.length() << " characters\n";


    return 0;
}