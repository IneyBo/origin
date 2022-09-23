#include <Windows.h>
#include <iostream>

class Figure
{
protected:
    unsigned short numberOfSides;
public:
    Figure()
    {
        numberOfSides = 0;
    }
    unsigned short getNumberOfSides()
    {
        return numberOfSides;
    }
};

class Triangle : public Figure
{
public:
    Triangle()
    {
        numberOfSides = 3;
    }
};

class Quadrilateral : public Figure
{
public:
    Quadrilateral()
    {
        numberOfSides = 4;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;

    std::cout << "���������� ������:" << std::endl
                << "������: " << figure.getNumberOfSides() << std::endl
                << "�����������: " << triangle.getNumberOfSides() << std::endl
                << "���������������: " << quadrilateral.getNumberOfSides() << std::endl;
    return 0;
}