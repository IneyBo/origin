#include <Windows.h>
#include <iostream>

class Figure // Класс фигура
{
protected:
    std::string name; // Имя фигуры для отображения в консоли
    unsigned short numberOfSides;

public:
    Figure()
    {
        name = "Фигура";
        numberOfSides = 0;
    }
    virtual bool isCorrect()
    {
        return true;
    }
    virtual void print() // Метод вывода в консоль
    {
        std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl;
        std::cout << std::endl;
    }
};

class Triangle : public Figure // Класс треугольник, наследник Figure
{
protected:
    unsigned long a; // Сторона a
    unsigned long b; // Сторона b
    unsigned long c; // Сторона c
    unsigned long A; // Угол A
    unsigned long B; // Угол B
    unsigned long C; // Угол C

public:
    Triangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Figure() // Конструктор
    {
        numberOfSides = 3;
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        //isCorrect = ((A + B + C) == 180) ? true : false; //Проверка корректности введенных данных
    }

    // Геттеры
    unsigned long get_a() const
    {
        return a;
    }
    unsigned long get_b() const
    {
        return b;
    }
    unsigned long get_c() const
    {
        return c;
    }
    unsigned long get_A() const
    {
        return A;
    }
    unsigned long get_B() const
    {
        return B;
    }
    unsigned long get_C() const
    {
        return C;
    }

    bool isCorrect() override
    {
        return ((A + B + C) == 180) ? true : false;
    }

    void print() override // Вывод в консоль
    {
        std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl
            << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle // Класс прямоугольный треугольник, наследник Triangle
{
public:
    RightTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B) : Triangle(a, b, c, A, B, C) //Конструктор
    {
        name = "Прямоугольный треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    }
};

class IsoscelesTriangle : public Triangle // Класс равнобедренный треугольник, наследник Triangle
{
public:
    IsoscelesTriangle(unsigned long a, unsigned long b, unsigned long A, unsigned long B) : Triangle(a, b, c, A, B, C)//Конструктор
    {
        name = "Равнобедренный треугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    }
};

class EquilateralTriangle : public Triangle // Класс равносторонний треугольник, наследник Triangle
{
public:
    EquilateralTriangle(unsigned long a) : Triangle(a, b, c, A, B, C)//Конструктор
    {
        name = "Равносторонний треугольник";
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;
    }
};

class Quadrilateral : public Triangle // Класс четырехугольник, наследник Triangle
{
protected:
    unsigned long d; // Сторона d
    unsigned long D; // Угол D

public:
    Quadrilateral(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Triangle(a, b, c, A, B, C)//Конструктор
    {
        numberOfSides = 4;
        name = "Четырехугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        //isCorrect = ((A + B + C + D) == 360) ? true : false;//Проверка корректности введенных данных
    }

    // Геттеры
    unsigned long get_d() const
    {
        return d;
    }
    unsigned long get_D() const
    {
        return D;
    }

    bool isCorrect() override
    {
        return ((A + B + C + D) == 360) ? true : false;
    }

    void print() override
    {
        std::cout << name << ":" << std::endl << (isCorrect() ? "Правильная" : "Неправильная") << std::endl << "Количество сторон: " << numberOfSides << std::endl << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl
            << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};

class RectangleThis : public Quadrilateral // Класс Прямоугольник, наследник Quadrilateral
{
public:
    RectangleThis(unsigned long a, unsigned long b) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
    {
        name = "Прямоугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
};

class Square : public Quadrilateral // Класс Квадрат, наследник Quadrilateral
{
public:
    Square(unsigned long a) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
    {
        name = "Квадрат";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
};

class Parallelogram : public Quadrilateral // Класс Параллелограмм, наследник Quadrilateral
{
public:
    Parallelogram(unsigned long a, unsigned long b, unsigned long A, unsigned long B) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
    {
        name = "Параллелограмм";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
};

class Rhomb : public Quadrilateral // Класс Ромб, наследник Quadrilateral
{
public:
    Rhomb(unsigned long a, unsigned long A, unsigned long B) : Quadrilateral(a, b, c, d, A, B, C, D)//Конструктор
    {
        name = "Ромб";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
};

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