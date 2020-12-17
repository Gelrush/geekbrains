#ifndef CATEGORIZER_H
#define CATEGORIZER_H

#include <iostream>
#include <fstream>
#include <cstring>

char* readLine(std::fstream& f, char end, char* result) {
    char sym = end + 1;

    for(int i = 0; sym != end; i++)
    {
        f.read(&sym, 1);
        result[i] = sym;
    }
    return result;
}


#endif
