#include "binary_int.h"

using namespace std;

int main(){
    binary_int a(-2);
    binary_int b(-2);
    binary_int c;

    // Присваивание
    c = a;
    cout << "c = " << c << endl;

    // Сложение
    binary_int sum = a + b;
    cout << "a + b = " << sum << endl;

    // Вычитание
    binary_int diff = a - b;
    cout << "a - b = " << diff << endl;

    // Унарный минус
    binary_int neg = -a;
    cout << "-a = " << neg << endl;

    // Инкремент префиксный
    ++a;
    cout << "++a = " << a << endl;

    // Инкремент постфиксный
    binary_int post_inc = a++;
    cout << "a++ = " << post_inc << endl;
    cout << "a after post-increment = " << a << endl;

    // Декремент префиксный
    --a;
    cout << "--a = " << a << endl;

    // Декремент постфиксный
    binary_int post_dec = a--;
    cout << "a-- = " << post_dec << endl;
    cout << "a after post-decrement = " << a << endl;

    // Сложение с присваиванием
    a += b;
    cout << "a += b = " << a << endl;

    // Вычитание с присваиванием
    a -= b;
    cout << "a -= b = " << a << endl;

    // Сдвиг влево
    binary_int shift_left = a << binary_int(2);
    cout << "a << 2 = " << shift_left << endl;

    // Сдвиг влево с присваиванием
    a <<= binary_int(2);
    cout << "a <<= 2 = " << a << endl;

    // Сдвиг вправо
    binary_int shift_right = a >> binary_int(2);
    cout << "a >> 2 = " << shift_right << endl;

    // Сдвиг вправо с присваиванием
    a >>= binary_int(2);
    cout << "a >>= 2 = " << a << endl;

    // Умножение
    binary_int product = a * b;
    cout << "a * b = " << product << endl;

    // Умножение с присваиванием
    a *= -b;
    cout << "a *= -b = " << a << endl;

    // Разделение битов
    pair<binary_int, binary_int> split = a.split_bits();
    cout << "High bits of a: " << split.first << endl;
    cout << "Low bits of a: " << split.second << endl;

    return 0;
}