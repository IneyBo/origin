#include <Windows.h>

#include <iostream>

#include "math_functions.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y;
    int operation;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;

    switch (operation)
    {
    case 1: 
        std::cout << x << " прибавить к " << y << " = " << addition(x, y);
        break;
    case 2:
        std::cout << y << " вычесть из " << x << " = " << substraction(x, y);
        break;
    case 3:
        std::cout << x << " умножить на " << y << " = " << multiplication(x, y);
        break;
    case 4:
        std::cout << x << " делить на " << y << " = " << division(x, y);
        break;
    case 5:
        std::cout << x << " в степени " << y << " = " << power(x, y);
        break;
    default:
        std::cout << "Вы ввели неверную команду. Попробуйте снова";
        break;
    }
    
    return 0;
}