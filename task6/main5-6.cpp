#include "vector.h"
#include <iostream>

void printVector(const vector& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Создание вектора с начальными значениями
    vector vec1(5, 2.0);
    std::cout << "vec1 after creation: ";
    printVector(vec1);

    // Добавление элементов в конец вектора
    vec1.push_back(3.0);
    vec1.push_back(4.0);
    std::cout << "vec1 after push_back: ";
    printVector(vec1);

    // Удаление последнего элемента
    vec1.pop_back();
    std::cout << "vec1 after pop_back: ";
    printVector(vec1);

    // Вставка элемента по индексу
    vec1.insert(2, 5.0);
    std::cout << "vec1 after insert at index 2: ";
    printVector(vec1);

    // Удаление элемента по индексу
    vec1.erase(1);
    std::cout << "vec1 after erase at index 1: ";
    printVector(vec1);

    // Изменение размера вектора
    vec1.resize(10, 1.0);
    std::cout << "vec1 after resize to 10 with value 1.0: ";
    printVector(vec1);

    // Создание вектора из итераторов
    vector vec2(vec1.begin(), vec1.end());
    std::cout << "vec2 created from vec1's iterators: ";
    printVector(vec2);

    // Сравнение векторов
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal" << std::endl;
    } else {
        std::cout << "vec1 and vec2 are not equal" << std::endl;
    }

    // Очистка вектора
    vec1.clear();
    std::cout << "vec1 after clear: ";
    printVector(vec1);

    // Проверка емкости вектора
    std::cout << "vec2 capacity before shrink_to_fit: " << vec2.capacity() << std::endl;
    vec2.shrink_to_fit();
    std::cout << "vec2 capacity after shrink_to_fit: " << vec2.capacity() << std::endl;

    return 0;
}