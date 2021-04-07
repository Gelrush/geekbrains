#include <iostream>

class Date
{
private:
    int day{ 1 };
    int month{ 1 };
    int year{ 2000 };
public:
    Date() {   }
    Date(int y, int m, int d) 
        : year(y), month(m), day(d)
    {   }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool setDay(int d)
    {
        if (d < 1 || d > 31)
            return false;
        day = d;
        return true;
    }
    bool setMonth(int m)
    {
        if (m < 1 || m > 12)
            return false;
        month = m;
        return true;
    }
    bool setYear(int y)
    {
        year = y;
        return true;
    }
 

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.year << '.' << date.month << '.' << date.day;
    return os;
}


/*Date laterDate(const Date* d1, const Date* d2)    // либо так
{
    int d1Hash = d1->getYear() * 1000 + d1->getMonth() * 10 + d1->getDay();
    int d2Hash = d2->getYear() * 1000 + d2->getMonth() * 10 + d2->getDay();
    
    if (d1Hash > d2Hash)
        return *d1;
    else
        return *d2;
}*/

std::unique_ptr<Date>& laterDate(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2)  
{
    int d1Hash = d1->getYear() * 1000 + d1->getMonth() * 10 + d1->getDay();
    int d2Hash = d2->getYear() * 1000 + d2->getMonth() * 10 + d2->getDay();

    if (d1Hash > d2Hash)
        return d1;
    else
        return d2;
}

void switchDate(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2)
{
    Date* tmp = d1.release();
    d1 = std::move(d2);
    d2 = std::unique_ptr<Date>(tmp);
}


int main(int argc, char const* argv[])
{
    auto date1 = std::make_unique<Date>(2021, 1, 1);
    auto date2 = std::make_unique<Date>(2020, 12, 31);
        
    //std::cout << laterDate(date1.get(), date2.get()) << std::endl;    // либо так
    std::cout << *laterDate(date1, date2) << std::endl;

    std::cout << "date1 = " << *date1 << std::endl;
    std::cout << "date2 = " << *date2 << std::endl;

    switchDate(date1, date2);

    std::cout << "date1 = " << *date1 << std::endl;
    std::cout << "date2 = " << *date2 << std::endl;


    return 0;
}