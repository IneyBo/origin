#include <string>

#include "parallelogram.h"
#include "figure_error.h"

Parallelogram::Parallelogram(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral()//Конструктор
{
    name = "Параллелограмм";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ") "; // Создание информации о фигуре

    if (!(a == c && b == d) && !(A == C && B == D)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a,c и b,d попарно не равны, углы A,C и B,D попарно равны");
    }
    else if (!(a == c && b == d)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: стороны a,c и b,d попарно не равны");
    }
    else if (!(A == C && B == D)) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: углы A,C и B,D попарно равны");
    }

    this->a = a;
    this->b = b;
    this->c = a;
    this->d = b;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}