#include "square.h"

Square::Square(unsigned long a) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
{
    name = "Квадрат";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = 90;
    this->B = 90;
    this->C = 90;
    this->D = 90;
}