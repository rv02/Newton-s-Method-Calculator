#ifndef DIV_H
#define DIV_H

#include <string>

class Div
{
    public:
        std::string Reciprocal(std::string s, int precision);
        std::string Division(std::string a, std::string b, int precision);
        std::string DivInt(std::string a, std::string b, int precision);
};
#endif