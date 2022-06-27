#include <iostream>
#include <fstream>
#include <cmath>

#include "Polynom.h"

int main() {

    Polynom first(4, std::vector<double>{1, 2, 3, 4, 5});
    std::cout << "1st:   " << first;
    Polynom second(2, std::vector<double>{2, 2, 2});
    std::cout << "2st:   " << second;
    std::cout << "Value of the first (x=3) is  " << first.getPolynom(3) << '\n';
    std::cout << "For the second value at 3 order (x=3) is  " << second.getPolynomAt(3, 3) << '\n';
    Polynom third = first + second;
    std::cout << "Sum:\t  " << third;
    Polynom six = (first - second);
    std::cout << "Sub1:\t  " << (third = first - second) << '\n';
    std::cout << "Sub:\t  " << six << '\n';
    Polynom seven = (first * second);
    std::cout << "Mult:\t " << seven << '\n';
    first.setCoefficientAt(3, 5.9);
    std::cout << "Value of the first after setting 5.9 at ^3  " << first;

    try {
        std::cout << "-1 value " << '\n';
        Polynom ten(-1, {0});
        std::cout << "Value ten is " << ten << '\n';
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "Negative value " << '\n';
        std::vector<double>coef(-1);
        Polynom eleven(4, coef);
        std::cout << "Value eleven is " << eleven << '\n';

    }
    catch (const std::logic_error &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}