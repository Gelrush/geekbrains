#ifndef CATEGORIZER_H
#define CATEGORIZER_H

#include <iostream>
#include <fstream>

int readLine(std::fstream& f, char end) {
    char sym;
    int result = 0;
    unsigned int digit_b = static_cast<unsigned int>(f.tellg());

    do {
        f.read(&sym, 1);
        std::cout << sym << " ";
    } while(sym != end);
    unsigned int digit_e = static_cast<unsigned int>(f.tellg()) - 2;

    for(int j = digit_e, c = 1; j >= digit_b; j--, c *= 10)
    {
        f.seekg(j);
        f.read(&sym, 1);
        result += (int) (sym - '0') * c;
    }

    f.seekg(digit_e + 2);
    return result;
}

#endif
