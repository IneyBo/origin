#include <iostream>

#pragma once

class Figure // Класс фигура
{
protected:
    std::string name; // Имя фигуры для отображения в консоли
    unsigned short numberOfSides;
    std::string figureInfo; // Информация о фигуре для вывода в консоль

public:
    Figure();
    Figure(int numberOfSides);
    void print(); // Метод вывода в консоль
};
