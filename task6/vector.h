#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H

#include <iostream>
#include <cstring>
#include <cmath>

class vector {
    double *array;
    size_t s;
    size_t cap;

    class iterator {
    private:
        double *ptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = double;
        using difference_type = std::ptrdiff_t;
        using pointer = double *;
        using reference = double &;

        iterator(double *p);

        reference operator*() const;

        pointer operator->();

        iterator &operator++();

        iterator operator++(int);

        iterator &operator--();

        iterator operator--(int);

        iterator &operator+=(difference_type n);

        iterator &operator-=(difference_type n);

        iterator operator+(difference_type n) const;

        iterator operator-(difference_type n) const;

        difference_type operator-(const iterator &other) const;

        reference operator[](difference_type n) const;

        bool operator==(const iterator &other) const;

        bool operator!=(const iterator &other) const;

        bool operator<(const iterator &other) const;

        bool operator<=(const iterator &other) const;

        bool operator>(const iterator &other) const;

        bool operator>=(const iterator &other) const;

        std::strong_ordering operator<=>(const vector::iterator &other) const;
    };

public:
    vector(size_t size, double value = 0.0);

    vector(vector::iterator first, vector::iterator last);

    vector(std::initializer_list<double> init);

    vector(const vector &vec);

    ~vector();

    vector &operator=(const vector &vec);

    iterator begin() const;

    iterator end() const;

    double &at(size_t index) const;

    double &front() const;

    double &back() const;

    double *data() const;

    bool empty() const;

    size_t size() const;

    void reserve(size_t num);

    size_t capacity() const;

    void shrink_to_fit();

    void clear();

    void push_back(double elem);

    void pop_back();

    void insert(size_t index, double elem);

    void erase(size_t index);

    void resize(size_t size, double elem);

    std::partial_ordering operator<=>(const vector &other) const;

    bool operator==(const vector &other) const;
};


#endif //LAB5_VECTOR_H
