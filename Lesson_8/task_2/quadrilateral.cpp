#include <string>
#include <iostream>

#include "quadrilateral.h"
#include "figure_error.h"

Quadrilateral::Quadrilateral()
{
    d = 0;
    D = 0;
}

Quadrilateral::Quadrilateral(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Triangle()//Конструктор
{
    numberOfSides = 4;
    name = "Четырехугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") "; // Создание информации о фигуре

    if ((A + B + C + D) != 360) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: сумма углов не равна 360");
    }

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