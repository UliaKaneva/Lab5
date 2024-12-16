#include "vector.h"

vector::iterator::iterator(double *p) : ptr(p) {}

double &vector::iterator::operator*() const { return *ptr; }

vector::iterator::pointer vector::iterator::operator->() { return ptr; }

vector::iterator &vector::iterator::operator++() {
    ++ptr;
    return *this;
}

vector::iterator vector::iterator::operator++(int) {
    iterator tmp = *this;
    ++ptr;
    return tmp;
}

vector::iterator &vector::iterator::operator--() {
    --ptr;
    return *this;
}

vector::iterator vector::iterator::operator--(int) {
    iterator tmp = *this;
    --ptr;
    return tmp;
}

vector::iterator &vector::iterator::operator+=(vector::iterator::difference_type n) {
    ptr += n;
    return *this;
}

vector::iterator &vector::iterator::operator-=(vector::iterator::difference_type n) {
    ptr -= n;
    return *this;
}

vector::iterator vector::iterator::operator+(vector::iterator::difference_type n) const { return {ptr + n}; }

vector::iterator vector::iterator::operator-(vector::iterator::difference_type n) const { return {ptr - n}; }

vector::iterator::difference_type vector::iterator::operator-(const vector::iterator &other) const { return ptr - other.ptr; }

double &vector::iterator::operator[](vector::iterator::difference_type n) const { return ptr[n]; }

bool vector::iterator::operator==(const vector::iterator &other) const { return ptr == other.ptr; }

bool vector::iterator::operator!=(const vector::iterator &other) const { return ptr != other.ptr; }

bool vector::iterator::operator<(const vector::iterator &other) const { return ptr < other.ptr; }

bool vector::iterator::operator<=(const vector::iterator &other) const { return ptr <= other.ptr; }

bool vector::iterator::operator>(const vector::iterator &other) const { return ptr > other.ptr; }

bool vector::iterator::operator>=(const vector::iterator &other) const { return ptr >= other.ptr; }

std::strong_ordering vector::iterator::operator<=>(const vector::iterator &other) const {
    if (ptr < other.ptr) return std::strong_ordering::less;
    if (ptr > other.ptr) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

vector::vector(size_t size, double value) {
    this->s = size;
    cap = (size == 0) ? 1: size * 2;
    array = new double[cap];
    std::fill_n(array, size, value);
    std::fill(array + size, array + cap, 0.0);
}

vector::vector(vector::iterator first, vector::iterator last) {
    this->s = std::distance(first, last);
    this->cap = (s == 0) ? 1: s * 2;
    this->array = new double[this->cap];
    std::copy(first, last, this->array);
}

vector::vector(std::initializer_list<double> init) {
    s = init.size();
    cap = (s == 0) ? 1: s * 2;
    array = new double[cap];
    std::copy(init.begin(), init.end(), array);
}

vector::vector(const vector &vec) {
    s = vec.s;
    cap = vec.cap;
    this->array = new double[this->cap];
    std::copy(vec.begin(), vec.end(), array);

}

vector::~vector() {
    delete[] array;
}

vector &vector::operator=(const vector &vec) {
    if (&vec != this) {
        delete[] array; // Освобождаем текущую память
        s = vec.s;
        cap = vec.cap;
        array = new double[cap];
        std::copy(vec.begin(), vec.end(), array);
    }
    return *this;
}

vector::iterator vector::begin() const { return {array}; }

vector::iterator vector::end() const { return {array + s}; }

double &vector::at(size_t index) const {
    if (index >= s) {
        throw std::invalid_argument("Index outside the vector");
    }
    return array[index];
}

double &vector::front() const {
    return array[0];
}

double &vector::back() const {
    return array[s - 1];
}

double *vector::data() const {
    return array;
}

bool vector::empty() const {
    return s == 0;
}

size_t vector::size() const {
    return s;
}

void vector::reserve(size_t num) {
    if (num > cap) {
        auto *newArr = new double[num];

        std::memcpy(newArr, array, s * sizeof(double));

        delete[] array;

        array = newArr;

        cap = num;
    }
}

size_t vector::capacity() const {
    return cap;
}

void vector::shrink_to_fit() {
    if (cap > s) {
        auto *newArr = new double[(s == 0) ? 1 : s];

        std::memcpy(newArr, array, s * sizeof(double));

        delete[] array;

        array = newArr;

        cap = s;
    }
}

void vector::clear() {
    s = 0;
}

void vector::push_back(double elem) {
    if (s >= cap) {
        this->reserve(s * 2);
    }
    array[s++] = elem;
}

void vector::pop_back() {
    s--;
}

void vector::insert(size_t index, double elem) {
    if (index > s) {
        throw std::invalid_argument("Index outside the vector");
    }
    double temp1 = elem;
    for (size_t i = index; i < s; i++) {
        double temp2 = array[i];
        array[i] = temp1;
        temp1 = temp2;
    }
    push_back(temp1);
}

void vector::erase(size_t index) {
    if (index >= s) {
        throw std::invalid_argument("Index outside the vector");
    }
    for (size_t i = index; i < s - 1; i++) {
        array[i] = array[i + 1];
    }
    s--;
}

void vector::resize(size_t size, double elem) {
    if (size > s) {
        for (size_t i = s; i < size; i++) {
            push_back(elem);
        }
    } else {
        s = size;
    }
}

std::partial_ordering vector::operator<=>(const vector &other) const {
    size_t minSize = std::min(size(), other.size());
    for (size_t i = 0; i < minSize; ++i) {
        if (fabs(array[i] - other.array[i]) > std::numeric_limits<double>::epsilon()) {
            return array[i] <=> other.array[i];
        }
    }
    return size() <=> other.size();
}

bool vector::operator==(const vector &other) const {
    return (*this <=> other) == 0;
}
