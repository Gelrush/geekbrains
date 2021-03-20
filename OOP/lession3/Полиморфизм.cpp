#include <iostream>
using namespace std;

// Полиморфизм — это способность обьекта использовать методы производного класса, 
// который не существует на момент создания базового.


class Parent // Виртуальные функции - метод класса который если был переопредел в дочернем классе
	// то конкреткная реализация метода будет определяться во время исполнения
{
protected:
    int m_age;
public:
    Parent(int age) : m_age(age) { }

    virtual ~Parent() // Деструктор виртуальный
    { cout << "Calling ~Parent()" << endl; }
    
    virtual int getAge() { return m_age; } // Виртуальный метод
};
class Child: public Parent
{
public:
    Child(int age) : Parent(age) { }

    ~Child() // Деструктор виртуальный
    { delete[] m_grades; }
    
    int getAge() override { return m_age / 2; }
};

void writeAge( Parent &someChild)
{
    cout << "rParent age " << someChild.getAge() << '\n';
}




class Animal // Абстрактный класс (где хоть бы один метод является асбтрактным)
{
public:
    virtual void say()=0; // чисто виртуальный метод (абстрактный)
};
class Cat: public Animal {
public:
    void say() { cout << "Meow" << endl; }
};
class Dog: public Animal
{
public:
    void say() { cout << "Woof" << endl; }
};




class IErrorLog // Интерфейсный класс - класс в котором нету членов и все методы абстрактны
	// обычно начинается с большой буквы I
{
public:
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;
    
    virtual bool writeError(const char *errorMessage) = 0;
    
    virtual ~IErrorLog() {}; // создаём виртуальный деструктор в случае, если удалим указатель на IErrorLog, то чтобы вызывался соответствующий деструктор дочернего класса
};




// Связывание - это процесс при котором компилятор сопоставляет имя с идентификатором адреса в памяти
// ранее - имя переменной к ее адресу
// позднее - указатель на функцию к самой функции
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }




class Animal // Проблема «алмаз смерти», которая возникает при множественном наследовании
{
public:
    Animal(char a[]) {
        cout << a << endl;
    }
};

class Cat: virtual public Animal // решается при помощи виртуальных базовых классов
{
public:
    Cat(char a[], char c[]) : Animal(a)
    {
        cout << c << endl;
    }
};

class Mouse: virtual public Animal
{
public:
    Mouse(char a[], char m[]) : Animal(a)
    {
        cout << m << endl;
    }
};

class Cartoon: public Cat, public Mouse
{
public:
    Cartoon(char a[], char c[], char m[]) :
    Cat(a,c), Mouse(a,m), Animal(a)
    { }
};





// Перегрузка операторов
class Dollars
{
private:
    int m_dollars;

public:
    Dollars(int dollars) { m_dollars = dollars; }
    	// // Перегрузка операторов через дружественные функции
    // выполняем Dollars + Dollars через дружественную функцию
    friend Dollars operator+ (const Dollars &d1, const Dollars &d2);

    // Эта функция является методом класса!
    // Вместо параметра dollars в перегрузке через дружественную функцию здесь неявный параметр, на который указывает указатель *this
    Dollars operator-(int value)
    {
        return Dollars(this->m_dollars - value);
    }


    int getDollars() const { return m_dollars; }
};
	// Перегрузка операторов через дружественные функции
Dollars operator+(const Dollars &d1, const Dollars &d2)
{
    // используем конструктор Dollars и operator+(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars + d2.m_dollars);
}

		// Перегрузка операторов через обычные функции
// Эта функция не является ни методом класса, ни дружественной классу Dollars!
Dollars operator+(const Dollars &d1, int d2)
{
    // используем конструктор Dollars и operator+(int, int)
    // здесь нам не нужен прямой доступ к закрытым членам класса Dollars
    return Dollars(d1.getDollars() + d2);
}
// Через методы класса нужно переопределять операторы присваивания (=), индекса ([]), вызова функции (()) и выбора члена (->). Это требование языка С++.
// Через методы класса нельзя переопределять операторы ввода (>>) и вывода (<<).
	// Унарный оператор (-a) - Перегрузка через метод класса
	// Бинарный оператор, не изменяющий левый операнд (a + b) - Перегрузка через обычную или дружественную функцию
	// Бинарный оператор, изменяющий левый операнд (a += b) - Перегрузка через метод класса

class Vector
{
private:
    double m_x, m_y, m_z;

public:
    Vector(double x = 0.0, double y = 0.0, double z = 0.0) :
    m_x(x), m_y(y), m_z(z)
    {
    }

    Vector operator- () const
    {
        return Vector(-m_x, -m_y, -m_z);
    }

    bool operator! () const
    {
        return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
    }

    double getX() {return m_x;}
    double getY() {return m_y;}
    double getZ() {return m_z;}
};



int main()
{
    Child child(40);
    Parent &rParent = child;
    writeAge(rParent); // вызовется метод дочернего класса


    Parent *parent = new Child(7);;
    delete parent; // вызовется деструктор дочернего класса


    Cat cat; // Объекты абстрактного класса создавать нельхя
    Dog dog;
    Animal *animal1 = &cat; // Можно создавать указатели на абстрактный класс
    Animal *animal2 = &dog;
    animal1 -> say(); // для каждого свой метод
    animal2 -> say();


    // Создаем указатель на функцию add
    using pF  = int (*)(int, int);
    pF = add;
    cout << pF(4, 5) << endl; // вызов add(4 + 5)
    pf = sub;
    cout << pF(4, 5) << endl; // вызов add(4 - 5)


    // В данном случа за создание базового класса отвечается класс Cartoon
    Cartoon animal("animal", "cat", "mouse"); // значала создается animal - cat - mouse


    Dollars dollars1(7);
    Dollars dollars2(9);
    Dollars dollarsSum = dollars1 + dollars2;
    cout << "I have " << dollarsSum.getDollars() << " dollars.";


    return 0;
}




