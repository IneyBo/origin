#include <string>

#include "triangle.h"
#include "figure_error.h"

Triangle::Triangle() : Figure()
{
    a = 0;
    b = 0;
    c = 0;
    A = 0;
    B = 0;
    C = 0;
}

Triangle::Triangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Figure() // Конструктор
{
    numberOfSides = 3;
    name = "Треугольник";

    figureInfo = name + " (стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ") "; // Создание информации о фигуре

    if ((A + B + C) != 180) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: сумма углов не равна 180");
    }

    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
}

// Геттеры
unsigned long Triangle::get_a() const
{
    return a;
}
unsigned long Triangle::get_b() const
{
    return b;
}
unsigned long Triangle::get_c() const
{
    return c;
}
unsigned long Triangle::get_A() const
{
    return A;
}
unsigned long Triangle::get_B() const
{
    return B;
}
unsigned long Triangle::get_C() const
{
    return C;
}