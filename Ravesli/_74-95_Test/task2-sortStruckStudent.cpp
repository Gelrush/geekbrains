<<<<<<< HEAD
﻿#include <iostream>
#include <string>
#include <algorithm>

namespace Constants
{
    const int maxStudents = 30;
    const int maxScore = 100;
}

struct Student
{
    std::string name;
    short score;
};

int getNum(int from, int to)
{
    int num;
    while (true)
    {
        std::cin >> num;

        if (std::cin.fail() || std::cin.peek() != '\n' || num < from || num > to)
        {
            std::cout << "Uncorrect number. ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
            return num;
    }
}

std::string getName()
{
    std::string name;
    std::cin >> name;
    return name;
}

Student* getArrStudent(const int len)
{
    Student* arr = new Student[len];
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << "Enter " << len - i << " students (name, score):\n";
        arr[i].name = getName();
        arr[i].score = getNum(0, Constants::maxScore);
    }
    return arr;
}

void sortStructStudent(Student *arr, const int count)
{
    for (size_t i = 0; i < count - 1; ++i)
        for (size_t j = i + 1; j < count; j++)
            if (arr[i].score < arr[j].score)
                std::swap(arr[i], arr[j]);
}

void printStudent(Student* arr, const int len)
{
    for (size_t i = 0; i < len; ++i)
        std::cout << arr[i].name << " got a grade of " << arr[i].score << std::endl;
}

int main() 
{   
    std::cout << "How many students in class room? ";
    int count = getNum(0, Constants::maxStudents);

    Student *arrStudent = getArrStudent(count);

    sortStructStudent(arrStudent, count);

    printStudent(arrStudent, count);

    delete[] arrStudent;

    return 0;
}
=======
﻿#include <iostream>
#include <string>
#include <algorithm>

namespace Constants
{
    const int maxStudents = 30;
    const int maxScore = 100;
}

struct Student
{
    std::string name;
    short score;
};

int getNum(int from, int to)
{
    int num;
    while (true)
    {
        std::cin >> num;

        if (std::cin.fail() || std::cin.peek() != '\n' || num < from || num > to)
        {
            std::cout << "Uncorrect number. ";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
            return num;
    }
}

std::string getName()
{
    std::string name;
    std::cin >> name;
    return name;
}

Student* getArrStudent(const int len)
{
    Student* arr = new Student[len];
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << "Enter " << len - i << " students (name, score):\n";
        arr[i].name = getName();
        arr[i].score = getNum(0, Constants::maxScore);
    }
    return arr;
}

void sortStructStudent(Student *arr, const int count)
{
    for (size_t i = 0; i < count - 1; ++i)
        for (size_t j = i + 1; j < count; j++)
            if (arr[i].score < arr[j].score)
                std::swap(arr[i], arr[j]);
}

void printStudent(Student* arr, const int len)
{
    for (size_t i = 0; i < len; ++i)
        std::cout << arr[i].name << " got a grade of " << arr[i].score << std::endl;
}

int main() 
{   
    std::cout << "How many students in class room? ";
    int count = getNum(0, Constants::maxStudents);

    Student *arrStudent = getArrStudent(count);

    sortStructStudent(arrStudent, count);

    printStudent(arrStudent, count);

    delete[] arrStudent;

    return 0;
}
>>>>>>> cd5f4ed8b4ea1fd1b8e9469926f22436e96790fd
