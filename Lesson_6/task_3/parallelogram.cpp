#include "parallelogram.h"

Parallelogram::Parallelogram(unsigned long a, unsigned long b, unsigned long A, unsigned long B) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
{
    name = "Параллелограмм";
    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}