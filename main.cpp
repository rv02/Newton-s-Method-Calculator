#include "karatsuba.h"
#include "div.h"
#include "squareRoot.h"
#include <iostream>

int set_flag() {
    char c;
    std::cout << "\n\nDo you wish to continue(Y/N): ";
    std::cin >> c;
    if (c == 'Y' || c == 'y') {
        return 1;
    }
    return 0;
}

int main() {
    bool flag = 1;
    while (flag == 1) {
        int ch;
        std::cout << "Calculator:";
        std::cout << "\n 1. Multiplication\n 2. Divison\n 3. Square-root \n 4. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> ch; 
        if (ch == 1) {
            Karatsuba k;
            std::string num1, num2;
            std::cout << "Enter two numbers to be multiplied:\n";
            std::cin >> num1 >> num2;
            std::cout << "\n" << k.Multiply(num1, num2);
            flag = set_flag();
        } else if (ch == 2) {
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
            flag = set_flag();
        } else if (ch == 3) 
        {
            
        }
        
        
    
    }
    
    
}