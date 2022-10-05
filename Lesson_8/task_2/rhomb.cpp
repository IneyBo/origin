#include <string>

#include "rhomb.h"
#include "figure_error.h"

Rhomb::Rhomb(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral()//Конструктор
{
    name = "Ромб";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") "; // Создание информации о фигуре

    if (!(a == b && b == c && c == d) && !(A == C && B == D)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны, углы A,C и B,D попарно не равны");
    }
    else if (!(a == b && b == c && c == d)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны");
    }
    else if (!(A == C && B == D)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: углы A,C и B,D попарно не равны");
    }

    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}