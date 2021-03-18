#include <iostream>
#include <string>

/*
Наследование в С++ происходит между классами. 
Родительский (базовый) класс — это тот, от которого наследуются свойства и методы. 
Дочерний (производный) класс — это тот, который наследует.

НЕ наследуется дочерним классом от предка:
1) Все конструкторы (по умолчанию, параметризированные);
2) Деструкторы;
3) Операторы (приведения, сравнения и пр.);
4) Дружественность
*/

class Date // Константные объекты классов
{
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date(int day, int month, int year);

    void setDate(int day, int month, int year);

    int getDay() const { return m_day; }
    int getMonth() const { return m_month; }
    int getYear() const { return m_year; }
};
// Мы передаем объект date по константной ссылке, чтобы избежать создания копии объекта date
void printDate(const Date& date)
{
    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
}
// Конструктор класса Date
Date::Date(int day, int month, int year)
{
    setDate(day, month, year);
}
// Метод класса Date
void Date::setDate(int day, int month, int year) // неявно добавляется аргумент - Date* const this
{
    this->m_day = day;
    this->m_month = month;
    this->m_year = year;
}


class Human
{
public:
    std::string m_name;
    int m_age;

    Human(std::string name = "", int age = 0)
        : m_name(name), m_age(age)
    {   }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
};
// Employee открыто наследует Human
class Employee : public Human // по умолчанию для классов private, для структур public
{
public:
    std::string m_employer;
    double m_wage;
    
    Employee(std::string employer, double wage)
        : m_employer(employer), m_wage(wage)
    { }

    Employee(std::string name = "", int age = 0, std::string employer = "", double wage = 0)
        : Human(name, age), // вызывается Human(std::string, int) для инициализации членов name и age
        m_employer(employer), m_wage(wage)
    { }

    std::string getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};




class Dog;
class Cat // Дружественные функции
{
private:
    int m_age;
    // Делаем функцию resetAge() дружественной классу Cat
    friend void resetAge(Cat& cat);
    friend void getAge(const Cat& cat, const Dog& dog);

};
class Dog
{
private:
    int m_age;
    friend void getAge(const Cat& cat, const Dog& dog);
};

// resetAge() теперь является другом класса Cat
void resetAge(Cat& cat)
{
    // И мы имеем доступ к закрытым членам объектов класса Cat
    cat.m_age = 0;
}

void getAge(const Cat& cat, const Dog& dog)
{
    // И мы имеем доступ к закрытым членам объектов классов Cat и Dog
    std::cout << cat.m_age << dog.m_age;
}




class Dog1
{
private:
    int m_age;
public:
    Dog1(int age) : m_age(age)
    { }
    // Делаем класс Cat другом классу Dog
    friend class Cat1;
};

class Cat1
{
private:
    int m_age;
public:
    Cat1(int age) : m_age(age)
    { }
    bool compareAge(Cat1& cat, Dog1& dog) {
        // у нас есть доступ к private переменным класса Dog
        return dog.m_age < cat.m_age;
    }
};



class Parent    // Спецификатор доступа protected
{
public:
    int m_public;           // доступ к этому члену открыт для всех объектов
private:
    int m_private;          // доступ к этому члену открыт только для других членов класса Parent и для дружественных классов/функций (но не для дочерних классов)
protected:
    int m_protected;        // доступ к этому члену открыт для других членов класса Parent, дружественных классов/функций, дочерних классов
};

class Child : public Parent
{
public:
    Child()
    {
        m_public = 1;     // разрешено: доступ к открытым членам родительского класса из дочернего класса
        //m_private = 2;    // запрещено: доступ к закрытым членам родительского класса из дочернего класса
        m_protected = 3;  // разрешено: доступ к защищенным членам родительского класса из дочернего класса
    }
};



class Animal {
protected:
    int m_age;
public:
    void set_age(int age) { m_age = age; }
    void show_age() { std::cout << m_age << std::endl; }
};

class Dog2 : public Animal {
    char m_breed[80];             // кличка собаки
public:
    void set_breed(const char* breed) {
        strcpy(m_breed, breed);
    };
    void show_breed() {
        std::cout << m_breed << std::endl;
    }
};





class School    // Множественное наследование
{
private:
    int m_number;
    std::string m_type;
public:
    School(int number, std::string type) : m_number(number), m_type(type)
    { }
};
class Employe
{
private:
    std::string m_employer;
    double m_wage;
public:
    Employe(std::string employer, double wage)
        : m_employer(employer), m_wage(wage)
    { }
};
// класс Teacher открыто наследует свойства классов Human и Employee
class Teacher : public School, public Employee
{
private:
    int m_teachesGrade;
public:
    Teacher(int number, std::string type, std::string employer, double wage, int teachesGrade)
        : School(number, type), Employee(employer, wage), m_teachesGrade(teachesGrade)
    { }
};




int main(int argc, char *argv[])
{
    Date date(12, 11, 2018);
    printDate(date);


    Employee anton;
    anton.m_name = "Anton";
    std::cout << anton.getName() << '\n'; // используем метод getName(), который мы унаследовали от класса Human


    Cat Frisky;
    Dog Ketty;
    resetAge(Frisky);
    getAge(Frisky, Ketty);


    Cat1 Frisky1(4);
    Dog1 Spike1(3);
    if (Frisky1.compareAge(Frisky1, Spike1))
        std::cout << "Кот старше собаки";
    else
        std::cout << "Кот не старше собаки";



    Animal* p_animal;
    Animal animal;
    Dog2 dog;

    p_animal = &animal;           // адрес объекта базового класса
                                  // доступ к Animal через указатель
    p_animal->set_age(5);         // доступ к Dog через указатель
    p_animal = &dog;
    p_animal->set_age(10);
        // показать каждое имя соответствующего объекта
    animal.show_age();
    dog.show_age();
    dog.set_breed("poodle");
    ((Dog2*) p_animal)->show_breed();




    return 0;
}
