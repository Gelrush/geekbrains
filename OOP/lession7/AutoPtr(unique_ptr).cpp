#include <iostream>

/* Неявное преобразование классов
*  Умные указатели */

class Bar
{
private:
    int m_x;
public:
    Bar() {   }                         // конструктор по умолчанию
    Bar(int x) : m_x(x) {   }           // конструктор с параметром
    explicit Bar(std::string str) {  }  // конструктор с параметром запрещающий неявное преобразование
    Bar(const Bar& b) { m_x = b.m_x; }  // конструктор копирования
    void operator=(const Bar& b) { m_x = b.m_x; }   // оператор присваивания

    int getX() { return m_x; }
    void print() { std::cout << m_x << std::endl; }
};


template<typename T>
class AutoPtr
{
private:
    T* m_ptr;
public:
    AutoPtr(const T* ptr) : m_ptr(ptr) { }
    AutoPtr(const AutoPtr&) = delete;
    void operator=(const AutoPtr&) = delete;
    //{ m_ptr = ptr.m_ptr; }      // поверхностное копирование (память одна, ссылки две) - плохо

    AutoPtr(AutoPtr&& p)    // контруктор перемещения (используя r-value ссылку)
    {
        m_ptr = p.m_ptr;
        p.m_ptr = nullptr;
    }
    void operator=(AutoPtr&& p) // оператор перемещения (передаваемая переменная больше не ссылается на данные)
    {
        m_ptr = p.m_ptr;
        p.m_ptr = nullptr;
    }
    
    ~AutoPtr() { delete m_ptr; }

    T* operator->() { return m_ptr; }
    T& operator*() { return &m_ptr; }

};

int main(int argc, char const* argv[])
{
    {
        Bar bar; // конструктор по умолчанию
        Bar bar2{ 5 }; // конструктор с параметром
        Bar bar3 = bar2; // конструктор копирования
        Bar bar4;
        bar3 = bar2; // оператор присваивания
        Bar bar4 = 'c'; // конструктор с параметров (неявное преобразование char в Bar(int) )
        std::string str = "c";
        Bar bar5 = str; // explicit запрещает неявное преобразование
    }
    {       // Пользовательский умный указатель
        //Bar* bar = new Bar();
        AutoPtr<Bar> bar(new Bar());
        bar->getX();
        Bar b = *bar;

        AutoPtr<Bar> bar2 = std::move(bar); // функция std::move создает r-value ссылку объекта Bar, вызывая контруктор перемещения
        bar = std::move(bar2);  // обратно, используя оператор перемещения

        //...
        int x = 4;
        //...
        if (x > 0)
        {
            //delete bar;
            exit(0);
        }
        //delete bar;
    }
    {       // std:: версии
        std::unique_ptr<Bar> bar = std::make_unique<Bar>(4); // = new Bar(4)
        bar->print();

        std::unique_ptr<Bar> bar2 = std::move(bar);

        if (bar) std::cout << "not null" << std::endl;
        else std::cout << "null" << std::endl;  // this

        bar.release(); // возвращает указатель и удаляет этот указатель из unique_ptr
        bar.get(); // возвращает указатель из unique_ptr
        bar.reset(); // удаляет указатель из unique_ptr

        std::shared_ptr<Bar> bar3 = std::make_shared<Bar>(5);
            // создаетсяумный указатель для нескольких переменных. 
        // При удалении одного из объектов память освобождаться не будет. 
        // Только при удалении всех переменных указывающих на одну и ту же переменную память будет освобождена
    }


    return 0;
}