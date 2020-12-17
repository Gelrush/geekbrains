#include "categorizer.hpp"

using namespace std;

unsigned int histogram[256];            // гистограмма цветовой гаммы пикселя
int alphabet[256];                      // массив для перевода символов из ASCII в цифры

int main(int argc, char** args) 
{
    fstream f;                          // входной поток файла
    ofstream out("histogram.txt");      // выходной поток файла
    int width = 0, height = 0;
    char sym;                           // буфер считывания символов
    char PGM_hdr1[2];                   // массив для считывания формата файла
    if(argc == 1)                       // по умолчанию передается путь проекта (argc при этом 1)
    {
        cout << "Please enter input files!";
        return 1;
    }
    for(int i = 1; i < argc; ++i)
    {
        cout << args[i] << endl;
        f.open(args[i],ios::binary | ios::in);
        if(!f.is_open())
        {
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;


        f.read(PGM_hdr1, 2);            // считывание 2х байт в массив
        if(PGM_hdr1[0] != 0x50 || PGM_hdr1[1] != 0x35)
            continue;                   // закончить, если формат не равен P5 (в 16ричном формате)
        cout << "PGM header detected" << endl;
        f.seekg(static_cast<unsigned int>(f.tellg()) + 1);
                                        // передвинуть каретку на 1 символ (пропустить 0x0A)
                                        // tellg() - вернуть текущее положение
                                        // приведение типа в unsigned int
        int j = 0;
        for(int d = '0'; d <= '9'; d++, j++)
            alphabet[d] = j;            // составление соотношения кодов ASCII с реальными цифрами

        /*   считывание ширины   */
        unsigned int digit_b = static_cast<unsigned int>(f.tellg());
                                        // запоминание положения начала ширины
        do {
            f.read(&sym, 1);            // считывание символов до пробела (0x20)
        } while(sym != 0x20);
        unsigned int digit_e = static_cast<unsigned int>(f.tellg()) - 2;
                                        // перемещение позиции на последнюю цифру ширины
        int c = 1;
        for(j = digit_e; j >= digit_b; j--, c *= 10)
        {                               // цикл для считывания в обратном порядке цифр ширины
            f.seekg(j);                 // перемещение каретки назад
            f.read(&sym, 1);
            width += alphabet[sym] * c; // 2 + 1*10 + 5*100 = 512
        }


        //f.seekg(static_cast<unsigned int>(f.tellg()) + 3);
        //height = readLine(f, 0x0A);

        /*   считывание высоты    */
        digit_b = digit_e + 2;
        do {
            f.read(&sym, 1);
        } while(sym != 0x0A);
        digit_e = static_cast<unsigned int>(f.tellg()) - 2;
        c = 1;
        for(j = digit_e; j >= digit_b; j--, c *= 10)
        {
            f.seekg(j);
            f.read(&sym, 1);
            height += alphabet[sym] * c;
        }

        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;

        for(int d = 0; d < 256; d++) histogram[d] = 0;
                                        // обнуление значений гистограммы
        f.seekg(digit_e + 6);           // перемещение на первый пиксель картинки
        for(int d = 0; d < (width * height); d++)
        {                               // считывание количества градиента для каждого цвета
            if(f.eof()) break;
            f.read(&sym, 1);
            histogram[static_cast<unsigned char>(sym)]++;
        }
        cout << endl;
        f.close();

        out << "File: " << args[i] << endl;
        out << "Width: " << width << "\t Height: " << height << endl;
        for(int d = 0; d < 256; d++)    // вывод на экран результатов гистограммы
        {
            out << "[" << d << "] ";
            for(int f = 0; f < histogram[d]; f++)
                out << "|";
            out << endl;
        }
        out << "End of file: " << args[i] << endl << endl;
    }
    out.close();
    return 0;
}

