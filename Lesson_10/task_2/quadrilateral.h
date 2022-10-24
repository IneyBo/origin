#pragma once
#include "triangle.h"

class Quadrilateral : public Triangle // Класс четырехугольник, наследник Triangle
{
protected:
    unsigned long d; // Сторона d
    unsigned long D; // Угол D

public:
    Quadrilateral(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D);//Конструктор

    // Геттеры
    unsigned long get_d() const;
    unsigned long get_D() const;

    bool isCorrect() override;

    void print() override;
};

