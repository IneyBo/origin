#include <iostream>

#pragma once

class Figure // Класс фигура
{
protected:
    std::string name; // Имя фигуры для отображения в консоли
    unsigned short numberOfSides;

public:
    Figure();
    virtual bool isCorrect();
    virtual void print(); // Метод вывода в консоль
};
