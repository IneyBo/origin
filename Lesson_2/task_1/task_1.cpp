#include <Windows.h>
#include <iostream>

enum class months
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULE,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int in = 1; // Вводимое число
    std::string outMonth; // Вывод месяца

    while (in != 0)
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> in;

        if (in == 0)
        {
            break;
        }

        months month = static_cast<months>(in); // Создание «экземпляра» перечисления

        switch (month)
        {
        case months::JANUARY:
            outMonth = "Январь";
            break;
        case months::FEBRUARY:
            outMonth = "Февраль";
            break;
        case months::MARCH:
            outMonth = "Март";
            break;
        case months::APRIL:
            outMonth = "Апрель";
            break;
        case months::MAY:
            outMonth = "Май";
            break;
        case months::JUNE:
            outMonth = "Июнь";
            break;
        case months::JULE:
            outMonth = "Июль";
            break;
        case months::AUGUST:
            outMonth = "Август";
            break;
        case months::SEPTEMBER:
            outMonth = "Сентябрь";
            break;
        case months::OCTOBER:
            outMonth = "Октябрь";
            break;
        case months::NOVEMBER:
            outMonth = "Ноябрь";
            break;
        case months::DECEMBER:
            outMonth = "Декабрь";
            break;
        default:
            outMonth = "Неправильный месяц";
        }

        std::cout << outMonth << std::endl;
    }

    std::cout << "До свидания" << std::endl;

    return 0;
}
