#include <string>

#include "equilateral_triangle.h"
#include "figure_error.h"

EquilateralTriangle::EquilateralTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle()//Конструктор
{
    name = "Равносторонний треугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ") "; // Создание информации о фигуре

    if (!(a == c && b == c) && (A != 60 || B != 60 || C != 60)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны, все углы не равны 60");
    }
    else if (!(a == c && b == c)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны");
    }
    else if (!(A == 60 && B == 60 && C == 60)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все углы не равны 60");
    }

    this->a = a;
    this->b = a;
    this->c = a;
    this->A = A;
    this->B = B;
    this->C = C;
}