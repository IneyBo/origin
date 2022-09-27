#include <Windows.h>

#include <iostream>

#include "counter.h"

Counter createCounter(std::string condition) // Создание экземпляра класса Counter
{
    if (condition == "да")
    {
        int count;
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> count;
        Counter counter(count);
        return counter;
    }
    else if (condition == "нет")
    {
        Counter counter;
        return counter;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string inString = " ";
    char operation = '+';
    int count = 1;

    while (inString != "да" && inString != "нет") // Проверяю на корректность введеных данных
    {
        std::cout << "Вы хотите указать начальное значение счетчика? Введите «да» или «нет»: ";
        std::cin >> inString;

        //std::cout << inString << std::endl;

        if (inString != "да" && inString != "нет")
        {
            std::cout << "Вы ввели некорректные данные. Попробуйте снова." << std::endl;
        }
    }

    Counter counter = createCounter(inString);

    while (operation != 'x')
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'(англ. икс))";
        std::cin >> operation;

        if (operation == '+')
        {
            counter.increment();
        }
        else if (operation == '-')
        {
            counter.decrement();
        }
        else if (operation == '=')
        {
            std::cout << counter.getCount() << std::endl;
        }
        else if (operation != 'x' && operation != '=' && operation != '-' && operation != '+') // Проверяю на корректность введеных данных
        {
            std::cout << "Вы ввели неверную команду. Попробуйте снова." << std::endl;
        }
    }

    std::cout << "До свидания!";
}