#ifndef LAB5_BINARY_INT_H
#define LAB5_BINARY_INT_H

#include <iostream>

class binary_int {
private:

public:
    int number;

    binary_int(int num);

    binary_int();

    ~binary_int()= default;

    binary_int(const binary_int &num);

    binary_int &operator=(const binary_int &num);

    binary_int operator+(const binary_int &num) const;

    binary_int operator-(const binary_int &num) const;

    binary_int operator<<(const binary_int &num) const;

    binary_int operator>>(const binary_int &num) const;

    binary_int operator*(const binary_int &num) const;

    binary_int &operator+=(const binary_int &num);

    binary_int &operator-=(const binary_int &num);

    binary_int &operator*=(const binary_int &num);

    binary_int &operator<<=(const binary_int &num);

    binary_int &operator>>=(const binary_int &num);

    binary_int operator-() const;

    binary_int &operator++();

    binary_int operator++(int);

    binary_int &operator--();

    binary_int operator--(int);

    std::pair<binary_int, binary_int> split_bits() const;
};

std::ostream& operator<<(std::ostream& stream, const binary_int& number);

#endif //LAB5_BINARY_INT_H
