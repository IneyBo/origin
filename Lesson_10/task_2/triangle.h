#pragma once
#include "figure.h"

class Triangle : public Figure // Класс треугольник, наследник Figure
{
protected:
    unsigned long a; // Сторона a
    unsigned long b; // Сторона b
    unsigned long c; // Сторона c
    unsigned long A; // Угол A
    unsigned long B; // Угол B
    unsigned long C; // Угол C

public:
    Triangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C); // Конструктор

    // Геттеры
    unsigned long get_a() const;
    unsigned long get_b() const;
    unsigned long get_c() const;
    unsigned long get_A() const;
    unsigned long get_B() const;
    unsigned long get_C() const;

    bool isCorrect() override;

    void print() override; // Вывод в консоль
};

