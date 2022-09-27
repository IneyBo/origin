#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(unsigned long a) : Triangle(a, b, c, A, B, C)//Конструктор
{
    name = "Равносторонний треугольник";
    this->a = a;
    this->b = a;
    this->c = a;
    this->A = 60;
    this->B = 60;
    this->C = 60;
}