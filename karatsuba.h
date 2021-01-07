#ifndef KARATSUBA_H
#define KARATSUBA_H

#include <string>

class Karatsuba
{
    public:
        void makeStringsEqual(std::string &s1, std::string &s2);
        void removeLeadingZeroes(std::string &s);
        std::string Shift(std::string &s, int pow);
        std::string add(std::string s1, std::string s2);
        std::string subtract(std::string s1, std::string s2);
        std::string Multiply(std::string s1, std::string s2);
};
#endif
