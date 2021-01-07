#include <string>
#include <iostream>
#include <sstream>
#include "karatsuba.h"
#include "div.h"
#include <cmath>

std::string shiftR(std::string s1, const int R)
{
    return s1.substr(0, s1.size() - R);
}

std::string Div::Reciprocal(std::string b, int precision)
{
    Karatsuba kar;
    precision++;
    int len = (b.size() > 8 ? 8 : b.size());
    // take the starting few digits of the no. calculate initial val
    std::string x0 = b.substr(0, len);
    std::string dividend{ "1" };
    dividend.append(len, '0');
    // calculation can be done for integers now to find inital x0
    x0 = std::to_string(stoi(dividend) / stoi(x0));
    // value of x0 now converted to str and precision increased
    if (precision >= b.size()) {
        x0.append(precision - b.size(), '0');
    } else {
        return "0";
    } // so if precision is still less after shifting by a digits, then it will clearly return 0 
    // precision doubles for each loop so only log2n iterations
    int i = 0;
    while(i <= int(std::log2(precision)) + 1)
    {
    //the formula
    x0 = kar.subtract(kar.Multiply("2", x0), shiftR(kar.Multiply(b, kar.Multiply(x0, x0)), precision));
    std::cout << x0 << "\n\n";
    i++;
    }
    std::cout << i << std::endl;
    return x0;  
}

std::string Div::Division(std::string a, std::string b, int precision)
{
    Karatsuba kar;
    std::string prod = kar.Multiply(a, Reciprocal(b, precision + a.size()));
    precision += a.size() + 1;
    // because multiplying with a clearly shifts the product by a.size() so for better results 
    // the result comes with a fe more precisions than asked for but meh..
    if (precision >= prod.length())
    {
        std::string zeros(precision - prod.length(), '0');
        prod = zeros + prod;
        return "0." + prod;
    }
    else
    {
        size_t i_cnt{ prod.length() - precision };
        size_t f_cnt{ precision - i_cnt };
        return f_cnt > 0 ?
                prod.substr(0, i_cnt) + '.' + prod.substr(i_cnt, f_cnt) :
                prod.substr(0, i_cnt);
    }
    return prod;
}

std::string Div::DivInt(std::string a, std::string b, int precision)
{
    Karatsuba kar;
    std::string prod = kar.Multiply(a, Reciprocal(b, precision + a.size()));
    // because multiplying with a clearly shifts the product by a.size() so for better results 
    // the result comes with a fe more precisions than asked for but meh..
    if (precision >= prod.length())
    {
        return prod.append(precision - prod.length(), '0');
    } 
    return prod.substr(0, precision);
}


/*int main()
{
    Div d;
    std::string a, b;
    int decimal;
    std::cout << "Enter a : ";
    std::cin >> a;
    std::cout << "Enter b : ";
    std::cin >> b;
    std::cout << "Precision : ";
    std::cin >> decimal;
    std::cout << "\n" << d.Division(a, b, decimal) << "\n";
    return 0;
}*/

