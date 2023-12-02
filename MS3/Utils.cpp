#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/*
Joshua Dinham
121572226
BTC200NAA
All work completed by me
*/
#include "Utils.h"
namespace sdds
{

    void delAlloCopy(char*& des, const char* src) {
        delete[] des;
        des = nullptr;
        if (src && src[0]) {
            des = new char[std::strlen(src) + 1];
            std::strcpy(des, src);
        }
    }

    char* dynRead(istream& istr, char delimeter)
    {
        char* str{};
        string toRead;
        getline(istr, toRead, delimeter);
        if (istr) {
            str = new char[strlen(toRead.c_str()) + 1];
            strcpy(str, toRead.c_str());
        }
        return str;
    }
}
