#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned long a, unsigned long b, unsigned long A, unsigned long B) : Triangle(a, b, c, A, B, C)//Конструктор
{
    name = "Равнобедренный треугольник";
    this->a = a;
    this->b = b;
    this->c = a;
    this->A = A;
    this->B = B;
    this->C = A;
}