#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
//#define NDEBUG

class Person
{
protected:
    std::string name;
    int age;
    int weight;
public:
    Person(std::string p_name = "", int p_age = 0, int p_weight = 0) 
        : name(p_name), age(p_age), weight(p_weight)
    {
        assert(p_age >= 0 && "Uncorrect Person::age");
        assert(p_weight >= 0 && "Uncorrect Person::weight");
    }

    std::string getName() const { return name; }
    int getAge() const          { return age; }
    int getWeight() const       { return weight; }

    void setName(std::string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        assert(age >= 0 && "Uncorrect Person::age");
        this->age = age;
    }
    void setWeight(int weight)
    {
        assert(weight >= 0 && "Uncorrect Person::weight");
        this->weight = weight;
    }

    void printPerson() const
    {
        std::string strAge = age ? ", years old " + std::to_string(age) : "";
        std::string strWeighs{ weight ? ", weigh " + std::to_string(weight) : "" };

        std::cout << name << strAge << strWeighs << std::endl;
    }
};

class Student : public Person
{
private:
    int yearStudy{ 0 };
    static int count;
public:
    Student()   { count++; }
    Student(int s_yearStudy, std::string p_name = "Undefined", int p_age = 0, int p_weight = 0)
        : Person(p_name, p_age, p_weight), yearStudy(s_yearStudy)
    { count++; }

    ~Student()  { count--; }
    
    int getYearStudy() const { return yearStudy; }
    static int getCount()    { return count; }
    void setYearStudy(int year)
    {
        yearStudy = year;
    }

    void inc()
    {
        yearStudy++;
    }

    void printStudent() const
    {
        this->printPerson();
        std::cout << "Is a " << yearStudy << " year student" << std::endl;
    }
};
int Student::count{ 0 };

std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );
    return s;
}

int main(int argc, char *argv[])
{
    Student arrSt[6];
    arrSt[0] = { 2, "Kitty", 18 };
    arrSt[1] = { 3, "Mark", 19 };
    arrSt[2] = { 1, "Andre", 17, 110 };
    arrSt[3] = { 1, "Vik" };
    arrSt[4] = { 2, "Pol" };
    arrSt[5] = { 2, "Den", 18, 80 };

    std::cout << Student::getCount() << " students in total\n";
    std::cout << "Enter search name of student: ";
    std::string name;
    std::getline(std::cin, name);

    int i;
    for (i = 0; i < Student::getCount(); i++)
    {
        if (!to_lower(name).compare(to_lower(arrSt[i].getName())))
        {
            arrSt[i].printStudent();
            break;
        }
    }
    if (i == Student::getCount())
        std::cout << "No such student exists!" << std::endl;

    return 0;
}
