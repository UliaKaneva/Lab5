#ifndef LAB5_LOGICAL_VALUES_ARRAY_H
#define LAB5_LOGICAL_VALUES_ARRAY_H


#include <iostream>

class logical_values_array {
    unsigned int value;
public:
    logical_values_array(unsigned int val = 0);

    logical_values_array(const logical_values_array &val);

    logical_values_array &operator=(const logical_values_array &num);

    unsigned int get_value() const;

    void set_value(unsigned int new_value);

    logical_values_array inversion() const;

    logical_values_array conjunction(const logical_values_array &num) const;

    logical_values_array disjunction(const logical_values_array &num) const;

    logical_values_array implication(const logical_values_array &num) const;

    logical_values_array coimplication(const logical_values_array &num) const;

    logical_values_array addition_modulo_2(const logical_values_array &num) const;

    logical_values_array equivalence(const logical_values_array &num) const;

    logical_values_array pierce_arrow(const logical_values_array &num) const;

    logical_values_array schaeffer_stroke(const logical_values_array &num) const;

    int equals(const logical_values_array &num) const;

    unsigned int get_bit(const unsigned int index) const;

    void in_str(char *str) const;
};

std::ostream &operator<<(std::ostream &stream, const logical_values_array &logicv);


#endif //LAB5_LOGICAL_VALUES_ARRAY_H
