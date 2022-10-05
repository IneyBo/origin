#include <iostream>
#include <string>

#include "figure.h"
#include "figure_error.h"

Figure::Figure()
{
    numberOfSides = 0;
}

Figure::Figure(int numberOfSides)
{
    name = "Фигура";
    this->numberOfSides = numberOfSides;
    figureInfo = name + " (количество сторон " + std::to_string(numberOfSides) + ") "; // Создание информации о фигуре
    if (numberOfSides > 0) // Проверка условий
    {
        throw FigureError(figureInfo + "не был создан. Причина: количество сторон больше 0");
    }
}

void Figure::print() // Вывод в консоль
{
    std::cout << figureInfo << "создан" << std::endl;
}