#include "logical_values_array.h"

logical_values_array::logical_values_array(unsigned int val) {
    value = val;
}

logical_values_array::logical_values_array(const logical_values_array &val) {
    value = val.value;
}

logical_values_array &logical_values_array::operator=(const logical_values_array &num) {
    if (&num != this) {
        value = num.value;
    }
    return *this;
}

unsigned int logical_values_array::get_value() const {
    return value;
}

void logical_values_array::set_value(unsigned int new_value) {
    value = new_value;
}

logical_values_array logical_values_array::inversion() const {
    logical_values_array res;
    res.set_value(~(this->value));
    return res;
}

logical_values_array logical_values_array::conjunction(const logical_values_array &num) const {
    logical_values_array res;
    res.set_value(value & num.value);
    return res;
}

logical_values_array logical_values_array::disjunction(const logical_values_array &num) const {
    logical_values_array res;
    res.set_value(this->value | num.value);
    return res;
}

logical_values_array logical_values_array::implication(const logical_values_array &num) const {
    logical_values_array res = this->inversion().disjunction(num);
    return res;
}

logical_values_array logical_values_array::coimplication(const logical_values_array &num) const {
    logical_values_array res = this->implication(num).inversion();
    return res;
}

logical_values_array logical_values_array::addition_modulo_2(const logical_values_array &num) const {
    logical_values_array res;
    res.set_value(this->value ^ num.value);
    return res;
}

logical_values_array logical_values_array::equivalence(const logical_values_array &num) const {
    logical_values_array res = this->inversion().addition_modulo_2(num);
    return res;
}

logical_values_array logical_values_array::pierce_arrow(const logical_values_array &num) const {
    logical_values_array res = this->inversion().disjunction(num.inversion());
    return res;
}

logical_values_array logical_values_array::schaeffer_stroke(const logical_values_array &num) const {
    logical_values_array res = this->inversion().conjunction(num.inversion());
    return res;
}

int logical_values_array::equals(const logical_values_array &num) const {
    return value == num.value;
}

unsigned int logical_values_array::get_bit(const unsigned int index) const {
    return !!(value & (1 << index));
}

void logical_values_array::in_str(char *str) const {
    if (!str) {
        throw std::invalid_argument("Null pointer");
    }
    int size = sizeof(unsigned int) << 3;
    for (unsigned int i = 0; i < size; i++) {
        str[size - 1 - i] = (get_bit(i)) ? '1' : '0';
    }
    str[size] = '\0';
}

std::ostream &operator<<(std::ostream &stream, const logical_values_array &logicv) {
    char temp[sizeof(unsigned int) << 3];
    logicv.in_str(temp);
    stream << temp;
    return stream;
}
