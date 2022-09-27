#include "right_triangle.h"

RightTriangle:: RightTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B) : Triangle(a, b, c, A, B, C) //Конструктор
{
    name = "Прямоугольный треугольник";
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = 90;
}