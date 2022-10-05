#include <string>

#include "isosceles_triangle.h"
#include "figure_error.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle()//Конструктор
{
    name = "Равнобедренный треугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ") "; // Создание информации о фигуре

    if (a != c && A != C)
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a и c не равны, углы A и C не равны");
    }
    else if (a != c) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a и c не равны");
    }
    else if (A != C)
    {
        throw FigureError(figureInfo + "не был создан. Причина: углы A и C не равны");
    }

    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}