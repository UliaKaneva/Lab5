#include <iostream>
#include "logical_values_array.h"

int main() {
    // Создаем два объекта класса logical_values_array
    logical_values_array a(0b10101010); // Пример значения
    logical_values_array b(0b11001100); // Пример значения

    // Вывод исходных значений
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Демонстрация операций
    logical_values_array inversion_a = a.inversion();
    logical_values_array conjunction_ab = a.conjunction(b);
    logical_values_array disjunction_ab = a.disjunction(b);
    logical_values_array implication_ab = a.implication(b);
    logical_values_array coimplication_ab = a.coimplication(b);
    logical_values_array addition_modulo_2_ab = a.addition_modulo_2(b);
    logical_values_array equivalence_ab = a.equivalence(b);
    logical_values_array pierce_arrow_ab = a.pierce_arrow(b);
    logical_values_array schaeffer_stroke_ab = a.schaeffer_stroke(b);

    // Вывод результатов операций
    std::cout << "Inversion of a: " << inversion_a << std::endl;
    std::cout << "Conjunction of a and b: " << conjunction_ab << std::endl;
    std::cout << "Disjunction of a and b: " << disjunction_ab << std::endl;
    std::cout << "Implication of a to b: " << implication_ab << std::endl;
    std::cout << "Coimplication of a to b: " << coimplication_ab << std::endl;
    std::cout << "Addition modulo 2 of a and b: " << addition_modulo_2_ab << std::endl;
    std::cout << "Equivalence of a and b: " << equivalence_ab << std::endl;
    std::cout << "Pierce arrow of a and b: " << pierce_arrow_ab << std::endl;
    std::cout << "Schaeffer stroke of a and b: " << schaeffer_stroke_ab << std::endl;

    // Проверка равенства
    std::cout << "a equals b: " << (a.equals(b) ? "true" : "false") << std::endl;

    // Получение бита по индексу
    unsigned int bit_index = 3; // Пример индекса
    std::cout << "Bit at index " << bit_index << " in a: " << a.get_bit(bit_index) << std::endl;

    return 0;
}