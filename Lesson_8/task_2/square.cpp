#include <string>

#include "square.h"
#include "figure_error.h"

Square::Square(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral()//Конструктор
{
    name = "Квадрат";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") "; // Создание информации о фигуре

    if (!(a == b && b == c && c == d) && (A != 90 || B != 90 || C != 90 || D != 90)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны, все углы не равны 90");
    }
    else if (!(a == b && b == c && c == d)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все стороны не равны");
    }
    else if (!(A == 90 && B == 90 && C == 90 && D == 90)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: все углы не равны 90");
    }

    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = 90;
    this->B = 90;
    this->C = 90;
    this->D = 90;
}