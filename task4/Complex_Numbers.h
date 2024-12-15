#ifndef LAB5_COMPLEX_NUMBERS_H
#define LAB5_COMPLEX_NUMBERS_H

#include <cmath>
#include <iostream>

class Complex_Numbers {
public:
    double real;
    double imaginary;

    Complex_Numbers();

    Complex_Numbers(double r, double i);

    Complex_Numbers(const Complex_Numbers &num);

    Complex_Numbers &operator=(const Complex_Numbers &num);

    Complex_Numbers operator+(const Complex_Numbers &num) const;

    Complex_Numbers operator-(const Complex_Numbers &num) const;

    Complex_Numbers operator*(const Complex_Numbers &num) const;

    Complex_Numbers operator/(const Complex_Numbers &num) const;

    [[nodiscard]] double cnabs() const;

    [[nodiscard]] double argument() const;

};

std::ostream &operator<<(std::ostream &stream, Complex_Numbers &num);

#endif //LAB5_COMPLEX_NUMBERS_H
