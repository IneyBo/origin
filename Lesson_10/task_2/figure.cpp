#include <iostream>

#include "figure.h"

Figure::Figure()
{
    name = "Фигура";
    numberOfSides = 0;
}
bool Figure::isCorrect()
{
    return true;
}
void Figure::print() // Метод вывода в консоль
{
    std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl;
    std::cout << std::endl;
}