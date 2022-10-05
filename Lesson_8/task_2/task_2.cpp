#include <Windows.h>

#include <iostream>

// Подключение классов фигур
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

// Подключение класса исключения
#include "figure_error.h"

void print_info(Figure* figure)//Печать в консоль
{
    figure->print();
}

//Первое решение, которое работает. Но здесь работа одновременно только с одной фигурой

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        //Figure figure(2);
        //figure.print();

        Triangle triangle(10, 20, 30, 50, 60, 71);
        triangle.print();

        //RightTriangle rightTriangle(10, 20, 30, 50, 60, 90);
        //rightTriangle.print();

        //IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 60);
        //isoscelesTriangle.print();

        //EquilateralTriangle equilateralTriangle(30, 30, 30, 60, 50, 60);
        //equilateralTriangle.print();

        //Quadrilateral quadrilateral(10, 20, 30, 40, 90, 90, 90, 80);
        //quadrilateral.print();

        //RectangleThis rectangle(10, 20, 10, 20, 90, 90, 90, 90);
        //rectangle.print();

        //Square square(10, 20, 10, 10, 60, 60, 60, 90);
        //square.print();

        //Parallelogram parallelogram(10, 20, 10, 60, 60, 90, 60, 90);
        //parallelogram.print();

        //Rhomb rhomb(10, 10, 10, 10, 60, 90, 60, 20);
        //rhomb.print();
    }
    catch (FigureError ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}


/*
// Второе решение. Здесь попытался завести сразу несколько экземпляров в мэйне, что бы разные фигуры сразу вывести. И «try»-«catch» в функцию убрать. Но при работе функции «void createFigure(Figure& typeOfFigure)» выскакивает ошибка в конструкторах фигур. На месте оператора «throw».

void createFigure(Figure& typeOfFigure)
{
    try
    {
        Figure* figure = &typeOfFigure;
        print_info(figure);
    }
    catch (FigureError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Фигура
    Figure figure(2);
    print_info(&figure);

    //Треугольник
    Triangle triangle(10, 20, 30, 50, 60, 71);
    createFigure(triangle);

    //Прямоугольный треугольник
    RightTriangle rightTriangle(10, 20, 30, 50, 60, 90);
    createFigure(rightTriangle);

    //Равнобедренный треугольник
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 60);
    createFigure(isoscelesTriangle);

    //Равносторонний треугольник
    EquilateralTriangle equilateralTriangle(30, 30, 30, 60, 50, 60);
    createFigure(equilateralTriangle);

    //Четырехугольник
    Quadrilateral quadrilateral(10, 20, 30, 40, 90, 90, 90, 80);
    createFigure(quadrilateral);

    //Прямоугольник
    RectangleThis rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    createFigure(rectangle);

    //Квадрат
    Square square(10, 20, 10, 10, 60, 60, 60, 90);
    createFigure(square);

    //Параллелограмм
    Parallelogram parallelogram(10, 20, 10, 60, 60, 90, 60, 90);
    createFigure(parallelogram);

    //Ромб
    Rhomb rhomb(10, 10, 10, 10, 60, 90, 60, 20);
    createFigure(rhomb);
}
*/