#include <iostream>

#include "quadrilateral.h"

Quadrilateral::Quadrilateral(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Triangle(a, b, c, A, B, C)//Конструктор
{
    numberOfSides = 4;
    name = "Четырехугольник";
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

// Геттеры
unsigned long Quadrilateral::get_d() const
{
    return d;
}
unsigned long Quadrilateral::get_D() const
{
    return D;
}

bool Quadrilateral::isCorrect()
{
    return ((A + B + C + D) == 360) ? true : false;
}

void Quadrilateral::print()
{
    std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl
        << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
}