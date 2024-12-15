#include "Complex_Numbers.h"


int main(){
    {
        Complex_Numbers num;
        std::cout << num << std::endl;
    }

    // Тест параметризованного конструктора
    {
        Complex_Numbers num(3.0, 4.0);
        std::cout << num << std::endl;
    }

    // Тест конструктора копирования
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2(num1);
        std::cout << num1 << ' ' << num2 << std::endl;
    }

    // Тест оператора присваивания
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2;
        num2 = num1;
        std::cout << num1 << ' ' << num2 << std::endl;
    }

    // Тест оператора сложения
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2(1.0, 2.0);
        Complex_Numbers result = num1 + num2;
        std::cout << num1 << " + " << num2 << " = " << result << std::endl;
    }

    // Тест оператора вычитания
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2(1.0, 2.0);
        Complex_Numbers result = num1 - num2;
        std::cout << num1 << " - " << num2 << " = " << result << std::endl;
    }

    // Тест оператора умножения
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2(1.0, 2.0);
        Complex_Numbers result = num1 * num2;
        std::cout << num1 << " * " << num2 << " = " << result << std::endl;
    }

    // Тест оператора деления
    {
        Complex_Numbers num1(3.0, 4.0);
        Complex_Numbers num2(1.0, 2.0);
        Complex_Numbers result = num1 / num2;
        std::cout << num1 << " / " << num2 << " = " << result << std::endl;
    }

    // Тест метода cnabs
    {
        Complex_Numbers num(3.0, 4.0);
        std::cout << "abs " << num << ": " << num.cnabs() << std::endl;
    }

    // Тест метода argument
    {
        Complex_Numbers num1(3.0, 4.0);
        std::cout << "argument " << num1 << ": " << num1.argument() << std::endl;

        Complex_Numbers num2(-3.0, 4.0);
        std::cout << "argument " << num2 << ": " << num2.argument() << std::endl;

        Complex_Numbers num3(-3.0, -4.0);
        std::cout << "argument " << num3 << ": " << num3.argument() << std::endl;

        Complex_Numbers num4(3.0, -4.0);
        std::cout << "argument " << num4 << ": " << num4.argument() << std::endl;
    }
    return 0;
}