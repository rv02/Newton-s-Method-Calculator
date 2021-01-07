#include <string>
#include <math.h>
#include <sstream>
#include <iostream>
#include "karatsuba.h"
#include "div.h"


std::string root(std::string a, int precision)
{
    int x;
    std::string x0;
    if(a.size() < 15)
    {
        x = floor(sqrt(std::stod(a)));
        x0 = std::to_string(x);
        x0.append(precision, '0');
    }
    else
    {
        x = floor(sqrt(stod(a.substr(0, 14))));
        x0 = std::to_string(x);
        x0.append((a.length() + 1) / 2 - 7 + precision, '0');
    }
    

    Div div;
    Karatsuba kar;
    size_t len = x0.size();
    int i = 0;
    a.append(len, '0');
    while (i < int(std::log2(precision)) + 1){
        // x = (x0 + a / x0) / 2
        std::string param = div.DivInt(a, x0, len);
        std::cout << "\n\nx0: "<< x0 <<"\nParam: " << param << "\n\n";
        x0 = div.DivInt(kar.add(x0, param), "2", len);
        i++;
    }

    return x0;
}


int main() 
{
    std::cout << "\n\n" << root("2", 600) << "\n\n";
    return 0;
}