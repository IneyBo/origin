#include <iostream>

#include "triangle.h"

Triangle::Triangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Figure() // Конструктор
{
    numberOfSides = 3;
    name = "Треугольник";
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}

// Геттеры
unsigned long Triangle::get_a() const
{
    return a;
}
unsigned long Triangle::get_b() const
{
    return b;
}
unsigned long Triangle::get_c() const
{
    return c;
}
unsigned long Triangle::get_A() const
{
    return A;
}
unsigned long Triangle::get_B() const
{
    return B;
}
unsigned long Triangle::get_C() const
{
    return C;
}

bool Triangle::isCorrect()
{
    return ((A + B + C) == 180) ? true : false;
}

void Triangle::print() // Вывод в консоль
{
    std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl
        << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}