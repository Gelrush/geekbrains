#include <iostream>
#include <string>

using namespace std;

struct Employee // писать с заглавной буквы
{
    short id;
    int age;
    double salary;
};

struct Triangle // начиная с С++11
{
    double length = 2.0; // нестатическая инициализация членов
    double width = 2.0; // установка "значений по умолчанию"
};

struct Company
{
    Employee CEO; // Employee - это структура внутри структуры Company 
    int numberOfEmployees;
};

void printInformation(Employee employee)
{
    std::cout << "ID: " << employee.id << "\n";
    std::cout << "Age: " << employee.age << "\n";
    std::cout << "Salary: " << employee.salary << "\n";
}

Employee getEmployee()
{
    Employee idx;
    idx = { 5, 40, 50 }; // подобное объявление доступно с С++11
    return idx;
}

int main()
{
    cout << "Hello World!\n";
    
    Employee john; // создаем отдельную структуру Employee для John-а
    john.id = 8; // присваиваем значение члену id структуры john
    john.age = 27; // присваиваем значение члену age структуры john
    john.salary = 32.17; // присваиваем значение члену salary структуры john

    Employee james = { 6, 29 }; // james.id = 6, james.age = 29, james.salary = 0.0 (инициализация по умолчанию)
    ++james.salary;

    Triangle z { 6, 29 }; // uniform-инициализация, совместима с нестатической инициализацией членов с C++14

    printInformation(john);
    printInformation(getEmployee());

    Company myCompany = { { 3, 35, 55000.0f }, 7 };
    cout << myCompany.CEO.salary << endl;

    std::cout << "The size of Employee is " << sizeof(Employee) << "\n"; // размер структуры, в основном больше суммы всех ее членов
        // sizeof(Employee) = 16; short+int+double = 14 - происходит это из за выравнивания данных



    return 0;
}