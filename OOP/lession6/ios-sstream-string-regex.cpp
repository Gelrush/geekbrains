#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> // для stringstream
#include <regex>

using namespace std;

class Date
{
private:
    int m_day, m_month, m_year;
public:
    Date(int d = 1, int m = 1, int y = 2019) : m_day(d), m_month(m), m_year(y)
    { }

    friend ostream& operator<< (ostream& out, const Date& date);
    friend istream& operator>> (istream& in, Date& date);
};

ostream& operator<< (ostream& out, const Date& date)        // Перегрузка оператора вывода
{
    out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
    return out;
}

istream& operator>> (istream& in, Date& date)
{
    // обратите внимание, параметр date (объект класса Date) должен быть не константным, чтобы мы имели возможность изменить члены класса
    in >> date.m_day;
    in >> date.m_month;
    in >> date.m_year;

    return in;
}



int main(int argc, char const* argv[])
{   
            // класс istream
    {
        char name[12];
        cin >> setw(12) >> name; // считывание 11 символов, остальные остаются в буфере
        cout << name << endl;
    }
    {
        char fio;
        cin.get(fio); // считывание символа в том числе пробельных
        cout << fio;
    }
    {
        char fio[30];
        cin.get(fio, 30); // считывание сразу нескольких символов в том числе пробельных
        cout << fio << endl; // get() не считывает символ новой строки
    }
    {
        char fio[30];
        cin.getline(fio, 30); // считывает символ новой строки
        cout << cin.gcount(); // количество символов, извлеченных последним getline()
    }
    {
        string fio;
        getline(cin, fio); // специальная версия из библиотеки string

        cin.ignore(); // Метод извлекает один символ из потока istream и игнорирует его
        cin.ignore(10); // Метод извлекает 10й символ из потока istream и игнорирует его
        cin.ignore(10, 't'); // Тоже самое, только метод прекращает работу, если встречается символ 't'
        cin.peek(); // Метод возвращает следующий символ потока без реального чтения его из потока istream
        cin.unget(); // Метод помещает в поток последний считанный символ таким образом, что его можно прочитать следующей операцией чтения
    }



            // класс ostream
    { // флаги
        enum {
            skipws,         // пропуск обобщенных пробелов для input
                    // поле выравнивания
            left,           // добавление перед значением
            right,          // после значения
            internal,       // добавление между знаком и значением
                    // основание целого
            dec,            // десятичная система счисления
            oct,            // восьмеричная система счисления
            hex,            // шестнадцатеричная система счисления
            showbase,       // показать основное целое
            showpoint,      // выдать нули в конце
            uppercase,      // если включен, то используются заглавные буквы
            showpos,        // если включен, то перед положительными числами указывается знак +

            scientific,     // используется экспоненциальная запись чисел типа с плавающей точкой
            fixed,          // используется десятичная запись чисел типа с плавающей точкой;
                    // сброс в выходной поток
            unitbuf,        // после каждой операции
            stdio,          // после каждого символа

            boolalpha,      // если включен, то логические значения выводятся как true/false
        };
    }
    {
        cout.setf(ios::showpos); // включаем флаг showpos
        cout << 30;     // +30.
        cout.unsetf(ios::showpos); // выключаем
    }
    {
        cout.setf(ios::dec, ios::basefield); // сначала выключаем
        cout.setf(ios::hex, ios::basefield); // потом включает нужный флаг
        cout << 30; // 1e

        cout << hex << 30; // или просто вот так
    }
    {
        cout.fill('*');
        cout << setfill('\\') <<setw(10) << right << 42564 << endl;     // \\\\\42564
    }


                // Потоковые классы и строки
    {
        stringstream myString;
        int nValue = 336000;
        double dValue = 12.14;
        myString << nValue << " " << dValue;

        string strValue1, strValue2;
        myString >> strValue1 >> strValue2;

        cout << strValue1 << " " << strValue2 << endl;      // 336000 12.14
    }
    {
        stringstream myString;
        myString << "336000 12.14"; // вставляем (числовую) строку в поток
        int nValue;
        double dValue;
        myString >> nValue >> dValue;
        cout << nValue << " " << dValue << endl;        // 336000 12.14

        myString.str("");  // очистить stringstream
        myString.clear();  // тоже самое только еще и сбрасывает флаги ошибок
    }
    {
        string s = "245";
        int x = stoi(s);
        double y = stod(s);
    }


                // Перегрузка оператора вывода
    {
        Date date(5, 4, 2019);
        cout << date;
    }
                // Перегрузка оператора ввода
    {
        Date date;
        cin >> date;
    }


                // класс string
    {
        string s = "Hello World";
        cout << s.size() << endl;       // 12
        cout << s.max_size() << endl;   // 18446744073709551599
        cout << s.capacity() << endl;   // 22
        s.clear();      // size - 0; capacity - 22
        cout << boolalpha << s.empty() << endl;     // true
        s.resize(6);        // Hello
        s.shrink_to_fit();      // size = capacity

        cout << s[2] << endl;       // l
        cout << s.at(2) << endl;    // l
        cout << s.front() << endl;  // H
        cout << s.back() << endl;   // d
        
        cout << s.find("o") << endl;    // 4
        cout << s.find("q") << endl;    // 18446744073709551599
        cout << boolalpha << (s.find("q") == string::npos) << endl;  // true
        cout << s.find("o", 5) << endl; // 7 - поиск после 5 позиции
        cout << s.rfind("o") << endl;   // 7 - поиск с конца

        s += "!!";      // добавление 
        s.append("!!"); // добавление

        s.push_back('!'); // добавление 1 символа
        s.insert(3, "??");  // добавляет в 3 позицию символы

        s.erase(3); // удаляет все символы после 3го
        s.replace(2, 3, "h");   // заменяет строку, 2(позиция) 3(количество символов) 'h'(на символ) - Heh World

        const char* s2 = s.c_str();
        const char* s3 = s.data();

        cout << s.substr(2, 5) << endl; // llo w
        s.compare(s2);      // s == s2
    }



                // regex
    {
        regex r("([\\w]+)@([\\w]{3,5}).([\\w]{2,5})");
        cmatch m;
        string s = "email@mail.ru";

        if (!regex_match(s.c_str(), m, r))
        {
            cout << m[0] << endl;   // email@mail.ru
            cout << m[1] << endl;   // email
            cout << m[2] << endl;   // mail
            cout << m[3] << endl;   // ru
        }
    }

    return 0;
}
