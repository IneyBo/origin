#include "rhomb.h"

Rhomb::Rhomb(unsigned long a, unsigned long A, unsigned long B) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
{
    name = "Ромб";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}