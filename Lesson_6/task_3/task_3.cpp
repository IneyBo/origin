#include <Windows.h>

#include <iostream>

#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrilateral.h"
#include "rectangle_this.h"
#include "square.h"
#include "parallelogram.h"
#include "rhomb.h"

void print_info(Figure* figure)//Печать в консоль
{
    figure->print();
}

void createFigure(Figure& typeOfFigure)//Убрал в эту функцию однотипные действия по созданию фигуры
{
    Figure* figure = &typeOfFigure;
    print_info(figure);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Фигура
    Figure figure;
    print_info(&figure);

    //Треугольник
    Triangle triangle(10, 20, 30, 50, 60, 70);
    createFigure(triangle);

    //Прямоугольный треугольник
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    createFigure(rightTriangle);

    //Равнобедренный треугольник
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    createFigure(isoscelesTriangle);

    //Равносторонний треугольник
    EquilateralTriangle equilateralTriangle(30);
    createFigure(equilateralTriangle);

    //Четырехугольник
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    createFigure(quadrilateral);

    //Прямоугольник
    RectangleThis rectangle(10, 20);
    createFigure(rectangle);

    //Квадрат
    Square square(10);
    createFigure(square);

    //Параллелограмм
    Parallelogram parallelogram(20, 30, 30, 40);
    createFigure(parallelogram);

    //Ромб
    Rhomb rhomb(30, 30, 40);
    createFigure(rhomb);

    return 0;
}