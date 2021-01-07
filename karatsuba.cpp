#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "karatsuba.h"

void Karatsuba::makeStringsEqual(std::string &s1, std::string &s2)
{
    std::string::size_type n1 = s1.size(), n2 = s2.size(), diff = abs(n1 - n2);
    std::string temp;
    temp.assign(diff, '0');
    if (n1 > n2){
        s2 = temp + s2;
    } else {
        s1 = temp + s1;
    }
}

void Karatsuba::removeLeadingZeroes(std::string &s)
{
    auto it = find_if(s.cbegin(), s.cend(), [](const char c){return c != '0';});
    s.erase(s.begin(), it);
}

std::string Karatsuba::Shift(std::string &s, int pow)
{
    return s.append(pow, '0');
}

std::string Karatsuba::add(std::string temp1, std::string temp2)
{
    std::string result = "";
    int carry = 0;
    makeStringsEqual(temp1, temp2);
    int i = temp1.size() - 1;
    while(i >= 0) {
        carry += (temp1[i] - '0') + (temp2[i] - '0');
        result = std::to_string(carry % 10) + result;
        carry = carry / 10;
        i--;
    }
    if (carry != 0){
        result = std::to_string(carry) + result;
    }
    return result;
}

// Assume s1 is always greater than s2
std::string Karatsuba::subtract(std::string temp1,std::string temp2)
{
    std::string result = "";
    int diff;
    makeStringsEqual(temp1, temp2);
    for (int i = temp1.size() - 1; i >= 0; i--)
    {
        diff = (temp1[i] - '0') - (temp2[i] - '0');
        if (diff >= 0){
            result = std::to_string(diff) + result;
        } else {
            for (int j = i - 1; j >= 0; j--)
            {
                if (temp1[j] == '0'){
                    temp1[j] = '9';
                } else {
                    temp1[j] -= 1;
                    break;
                }
            }
            result = std::to_string(diff + 10) + result;
        }
    }
    removeLeadingZeroes(result);
    return result;
}


std::string Karatsuba::Multiply(std::string x, std::string y)
{
    std::string x1, x0, y1, y0;
    std::string z, z0, z1, z2;
    makeStringsEqual(x, y);
    int n = std::max(x.size(), y.size()), leftHalf, rightHalf;
    if(n <= 4){
        return std::to_string(std::stoi(x) * std::stoi(y));
    } else {
        leftHalf = n / 2;
        rightHalf = n - leftHalf;   
        
        x1 = x.substr(0, leftHalf);         // floor(n / 2) digits
        x0 = x.substr(leftHalf, rightHalf); // ceil(n / 2) digits
        
        y1 = y.substr(0, leftHalf);
        y0 = y.substr(leftHalf, rightHalf);
    
        z0 = Multiply(x0, y0);
        z2 = Multiply(x1, y1);
        z1 = subtract(subtract(Multiply(add(x0, x1), add(y0, y1)), z0), z2);
        z = add(add(Shift(z2, 2 * rightHalf), Shift(z1, rightHalf)), z0);
        removeLeadingZeroes(z);
        
        return z;
    }
}



