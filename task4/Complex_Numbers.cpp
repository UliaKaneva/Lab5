#include "Complex_Numbers.h"

Complex_Numbers::Complex_Numbers() {
    real = 0;
    imaginary = 0;
}

Complex_Numbers::Complex_Numbers(double r, double i) {
    real = r;
    imaginary = i;
}

Complex_Numbers::Complex_Numbers(const Complex_Numbers &num) {
    real = num.real;
    imaginary = num.imaginary;
}

Complex_Numbers &Complex_Numbers::operator=(const Complex_Numbers &num) {
    if (&num != this) {
        real = num.real;
        imaginary = num.imaginary;
    }
    return *this;
}

Complex_Numbers Complex_Numbers::operator+(const Complex_Numbers &num) const {
    Complex_Numbers res(*this);
    res.real += num.real;
    res.imaginary += num.imaginary;
    return res;
}

Complex_Numbers Complex_Numbers::operator-(const Complex_Numbers &num) const {
    Complex_Numbers res(*this);
    res.real -= num.real;
    res.imaginary -= num.imaginary;
    return res;
}

Complex_Numbers Complex_Numbers::operator*(const Complex_Numbers &num) const {
    Complex_Numbers res;
    res.real = real * num.real - imaginary * num.imaginary;
    res.imaginary = real * num.imaginary + imaginary * num.real;
    return res;
}

Complex_Numbers Complex_Numbers::operator/(const Complex_Numbers &num) const {
    Complex_Numbers res(num);
    res.imaginary = -res.imaginary;
    double d = num.real * num.real + num.imaginary * num.imaginary;
    res = *this * res;
    res.real /= d;
    res.imaginary /= d;
    return res;
}

double Complex_Numbers::cnabs() const {
    return sqrt(real * real + imaginary * imaginary);
}

double Complex_Numbers::argument() const {
    if (real == 0) {
        if (imaginary > 0)
            return M_PI / 2;
        else if (imaginary < 0)
            return -M_PI / 2;
        else
            return 0;
    }

    double res = atan(imaginary / real);

    if (imaginary > 0 && real < 0)
        res += M_PI;
    else if (imaginary < 0 && real < 0)
        res -= M_PI;

    return res;
}

std::ostream &operator<<(std::ostream &stream, Complex_Numbers &num) {
    if (num.real != 0)
        stream << num.real;

    if (num.imaginary == 0) {
        if (num.real == 0)
            stream << 0;
        return stream;
    }
    if (num.imaginary > 0){
        stream << '+';
    }

    stream << num.imaginary << "i";

    return stream;
}
