#include "categorizer.hpp"

using namespace std;

unsigned int histogram[256];

int main(int argc, char** args) 
{
    fstream f;
    char buffer[32], sym;
    ofstream out("histogram.txt");

    if(argc == 1)
    {
        cout << "Please enter input file!";
        return 1;
    }

    f.open(args[1],ios::binary | ios::in);
    if(!f.is_open())
    {
        cout << "File: " << args[1] << " is not accessible!" << endl;
        return 1;
    }

    if(!strcmp(readLine(f, 0x0A, buffer), "P5"))
    {
        cout << "File of unknown format!" << endl;
        return 1;
    } else cout << "PGM header detected" << endl;


    int width = stoi(readLine(f, 0x20, buffer));        // считывание строки в буффер
    int height = stoi(readLine(f, 0x0A, buffer));       // до определенного символа
    int bright = stoi(readLine(f, 0x0A, buffer));       // и конвертирование его в int

    for(int i = 0; i < 256; i++) histogram[i] = 0;
    for(int i = 0; !f.eof(); i++)
    {
        f.read(&sym, 1);
        histogram[static_cast<unsigned char>(sym)]++;
    }
    f.close();

    out << "File: " << args[1] << endl;
    out << "Width: " << width << "\t Height: " << height
         << "\t Max brightness value: " << bright << endl;

    for(int i = 0; i < 256; i++)
    {
        out << "[" << i << "] ";
        for(unsigned int f = 0; f < histogram[i]; f++)
            out << "|";
        out << endl;
    }

    out.close();

    return 0;
}

