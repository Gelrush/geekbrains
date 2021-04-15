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


int main(int argc, char const* argv[])
{
    
    auto today = std::make_unique<Date>();
    auto date = std::make_unique<Date>();

    today->setYear(2021);
    today->setMonth(4);
    today->setDay(4);

    std::cout << "Today - " << *today << std::endl;

    date = std::move(today);

    if (today) std::cout << "Value 'today' [" << *today << "]\n";
    else std::cout << "Value 'today' [nullptr]\n";

    if (date) std::cout << "Value 'date' [" << *date << "]\n";
    else std::cout << "Value 'date' [nullptr]\n";

    return 0;
}