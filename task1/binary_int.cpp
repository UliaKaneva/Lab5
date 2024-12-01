#include "binary_int.h"


binary_int::binary_int(int num) {
    number = num;
}

binary_int::binary_int() {
    number = 0;
}

binary_int::binary_int(const binary_int &num) {
    number = num.number;
}

binary_int& binary_int::operator=(const binary_int &num) {
    if (&num != this) {
        number = num.number;
    }
    return *this;
}
binary_int binary_int::operator+(const binary_int& num) const{
    binary_int res(*this);
    res += num;
    return res;

}
binary_int& binary_int::operator+=(const binary_int &num) {
    int a = number;
    int b = num.number;
    int carry = 0;
    while (b != 0) {
        carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    number = a;
    return *this;
}
binary_int binary_int::operator-(const binary_int& num) const{
    return (*this) + (-num);
}
binary_int& binary_int::operator-=(const binary_int& num){
    *this += -num;
    return *this;
}
binary_int& binary_int::operator++() {
    int nums = 1;
    while (number & nums) {
        number = number ^ nums;
        nums <<= 1;
    }
    number |= nums;
    return *this;
}
binary_int binary_int::operator++(int) {
    binary_int copy(number);
    ++(*this);
    return copy;
}
binary_int& binary_int::operator--() {
    int nums = 1;
    while (!(number & nums) && nums) {
        number = number | nums;
        nums <<= 1;
    }
    number = number ^ nums;
    return *this;
}

binary_int binary_int::operator--(int) {
    binary_int copy(number);
    --(*this);
    return copy;
}

binary_int binary_int::operator-() const {
    binary_int res;
    binary_int mod_this;
    mod_this.number = ~number;
    binary_int ed(1);
    res = mod_this + ed;
    return res;
}

binary_int& binary_int::operator<<=(const binary_int& num){
    number <<= num.number;
    return *this;
}
binary_int& binary_int::operator>>=(const binary_int& num){
    number >>= num.number;
    return *this;
}
binary_int binary_int::operator<<(const binary_int& num) const{
    binary_int res = *this;
    res <<= num;
    return res;
}
binary_int binary_int::operator>>(const binary_int& num) const{
    binary_int res = *this;
    res >>= num;
    return res;
}

binary_int binary_int::operator*(const binary_int &num) const {
    binary_int res(*this);
    res *= num;
    return res;
}

binary_int &binary_int::operator*=(const binary_int &num) {
    binary_int a(*this);
    number = 0;
    for (binary_int i(0); i.number < sizeof(int) * 8; ++i){
        if (num.number & (1 << i.number)){
            *this += a << i;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const binary_int& number)
{
    binary_int size(8 * sizeof(int));
    size -= binary_int(1);
    int num[8 * sizeof(int)];
    for (binary_int i(0); i.number < 8 * sizeof(int); ++i){
        num[(size - i).number] = ((1 << i.number) & number.number) != 0;
    }
     for (binary_int i(0); i.number < 8 * sizeof(int); ++i){
         stream << num[i.number];
     }
    return stream;


}
std::pair<binary_int, binary_int> binary_int::split_bits() const {
    binary_int half_bits = 1 << sizeof(int) * 4;
    --half_bits;
    binary_int high_bits(this->number & (~half_bits.number));
    binary_int low_bits(this->number & half_bits.number);
    return std::make_pair(high_bits, low_bits);
}

