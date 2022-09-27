#include "rectangle_this.h"

RectangleThis::RectangleThis(unsigned long a, unsigned long b) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
{
    name = "Прямоугольник";
    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    this->A = 90;
    this->B = 90;
    this->C = 90;
    this->D = 90;
}