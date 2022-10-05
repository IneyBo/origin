#include <string>

#include "rectangle_this.h"
#include "figure_error.h"

RectangleThis::RectangleThis(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral()//Конструктор
{
    name = "Прямоугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") "; // Создание информации о фигуре

    if (!(a == c && b == d) && (A != 90 || B != 90 || C != 90 || D != 90)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a,c и b,d попарно не равны, все углы не равны 90");
    }
    else if (!(a == c && b == d)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a,c и b,d попарно не равны");
    }
    else if (!(A == 90 && B == 90 && C == 90 && D == 90)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все углы не равны 90");
    }

    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}