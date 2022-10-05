#include <string>

#include "right_triangle.h"
#include "figure_error.h"

RightTriangle:: RightTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle() //Конструктор
{
    name = "Прямоугольный треугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ") "; // Создание информации о фигуре

    if (C != 90) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: угол С не равен 90");
    }

    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}