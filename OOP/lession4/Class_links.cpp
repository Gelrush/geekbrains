#include <iostream>
#include <string>
using namespace std;

// Композиция - это построение сложного объекта из более простых, которые являются его частью.
// член может принадлежать только одному классу
class Human_k
{
public:
    void Think() { brain.Think(); }
private:
    class Brain
    {
    public:
        void Think() { cout << "I think!" << endl; }
    };
    Brain brain;
};



// Агрегация - более слабая связть чем в композиции.
// член может и не принадлежать классу; член может существовать не под управлением класса
class Cap {
public:
    string getColor() { return color; }
private:
    string color = "red";
};
class Human_a
{
public:
    void InspectTheCap() {
        cout << "My cap has " << cap.getColor() << " color.\n";
    }
private:
    Cap cap;
};


class Worker
{
private:
    string m_name;

public:
    Worker(string name) : m_name(name)
    { }
    string getName() { return m_name; }
};
class Department
{
private:
    // Для простоты добавим только одного работника
    Worker* m_worker;
public:
    Department(Worker* worker = nullptr) : m_worker(worker)
    {  }
};



// Ассоциация - это отношение, при котором объекты одного типа неким образом связаны с объектами другого типа.
// Один объект может принадлежать одновременно сразу нескольким объектам; объекты могут знать о друг друге
// Например, игрок играет в определенной команде
class Car
{
private:
    string m_name;
    int m_id;
public:
    Car(string name, int id) : m_name(name), m_id(id) { }
    string getName() { return m_name; }
    int getId() { return m_id; }
};

// Данный класс содержит автомобили и имеет функцию для "выдачи" автомобиля
class CarLot
{
private:
    static Car s_carLot[4];
public:
    // Удаляем конструктор по умолчанию, чтобы нельзя было создать объект этого класса
    CarLot() = delete;

    static Car* getCar(int id)
    {
        for (int count = 0; count < 4; ++count)
            if (s_carLot[count].getId() == id)
                return &(s_carLot[count]);
        return nullptr;
    }
};
Car CarLot::s_carLot[4] = { Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 58) };

class Driver
{
private:
    string m_name;
    int m_carId; // для связывания классов используется эта переменная

public:
    Driver(string name, int carId) : m_name(name), m_carId(carId)
    {  }
    string getName() { return m_name; }
    int getCarId() { return m_carId; }

};



// Динамическое приведение типов (dynamic_cast)
class Parent
{
protected:
    string m_name;

public:
    Parent(string name) : m_name(name)
    { }
    virtual ~Parent() {}
};

class Child : public Parent
{
protected:
    string m_patronymic;

public:
    Child(string name, string patronymic) :
        Parent(name), m_patronymic(patronymic)
    { }
    const string& getName() { return m_name; }
};


int main(int argc, char *argv[])
{
    {
        Human_k human;
        human.Think();
    }
    {
        Human_a human;
        human.InspectTheCap();

        // Создаем нового работника
        Worker* worker = new Worker("Anton");
        {
            // Создаем Отдел и передаем Работника в Отдел через параметр конструктора
            Department department(worker);
        } // department выходит из области видимости и уничтожается здесь

        // worker продолжает существовать
        cout << worker->getName() << " still exists!";
        delete worker;
    }
    {
        Driver d("Ivan", 14); // Ivan ведет машину с ID 14

        Car* car = CarLot::getCar(d.getCarId()); // Получаем этот Автомобиль из CarLot

        if (car)
            cout << d.getName() << " is driving a " << car->getName() << '\n'; // Ivan is driving a Focus
        else
            cout << d.getName() << " couldn't find his car\n"; 
    }
    {
        Parent* p = new Child("Alex", "Mike");
        // используем dynamic_cast для конвертации указателя класса Parent в указатель класса Child
        Child* ch = dynamic_cast<Child*>(p); // возвращает nullptr если приведение не удалось
        cout << "The name of the Child is: " << ch->getName() << '\n';
        delete p;
        // динамическое приведение рабтает только если:
            // наследование типа public
            // класс предок является полиморфным (имеет виртуальные методы)
    }



    return 0;
}
