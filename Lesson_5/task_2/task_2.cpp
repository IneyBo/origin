#include <Windows.h>
#include <iostream>

class Figure // ����� ������
{
protected:
    bool isCorrect = true; // ���������� ��� �������� ��������� ������
    std::string name; // ��� ������ ��� ����������� � �������

public:
    Figure()
    {

    }
    virtual void print() // ����� ������ � �������
    {

    }
    bool getISCorrect() const // ������ ���������� �������� ��������� ������
    {
        return isCorrect;
    }
    std::string getName() const // ������ ����� ������
    {
        return name;
    }
};

class Triangle : public Figure // ����� �����������, ��������� Figure
{
protected:
    unsigned long a; // ������� a
    unsigned long b; // ������� b
    unsigned long c; // ������� c
    unsigned long A; // ���� A
    unsigned long B; // ���� B
    unsigned long C; // ���� C

public:
    Triangle (unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Figure() // �����������
    {
        name = "�����������";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    // �������
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

    void print() override // ����� � �������
    {
        std::cout   << "�������: a=" << a << " b=" << b << " c=" << c << std::endl
                    << "����: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle // ����� ������������� �����������, ��������� Triangle
{
public:
    RightTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle(a, b, c, A, B, C) //�����������
    {
        name = "������������� �����������";
        if (C == 90)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class IsoscelesTriangle : public Triangle // ����� �������������� �����������, ��������� Triangle
{
public:
    IsoscelesTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle(a, b, c, A, B, C)//�����������
    {
        name = "�������������� �����������";
        if (a == c && A == C)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class EquilateralTriangle : public Triangle // ����� �������������� �����������, ��������� Triangle
{
public:
    EquilateralTriangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Triangle(a, b, c, A, B, C)//�����������
    {
        name = "�������������� �����������";
        if (a == c && a == b && A == 60 && B == 60 && C == 0)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class Quadrilateral : public Triangle // ����� ���������������, ��������� Triangle
{
protected:
    unsigned long d; // ������� d
    unsigned long D; // ���� D

public:
    Quadrilateral(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Triangle(a, b, c, A, B, C)//�����������
    {
        name = "���������������";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    // �������
    unsigned long get_d() const
    {
        return d;
    }
    unsigned long get_D() const
    {
        return D;
    }

    void print() override
    {
        std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl
            << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};

class RectangleThis : public Quadrilateral // ����� �������������, ��������� Quadrilateral
{
public:
    RectangleThis(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral(a, b, c, d, A, B, C, D)//�����������
    {
        name = "�������������";
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class Square : public Quadrilateral // ����� �������, ��������� Quadrilateral
{
public:
    Square(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral(a, b, c, d, A, B, C, D)//�����������
    {
        name = "�������";
        if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class Parallelogram : public Quadrilateral // ����� ��������������, ��������� Quadrilateral
{
public:
    Parallelogram(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral(a, b, c, d, A, B, C, D)//�����������
    {
        name = "��������������";
        if (a == c && b == d && A == C && B == D)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        else
        {
            isCorrect = false;
        }
    }
};

class Rhomb : public Quadrilateral // ����� ����, ��������� Quadrilateral
{
public:
    Rhomb(unsigned long a, unsigned long b, unsigned long c, unsigned long d, unsigned long A, unsigned long B, unsigned long C, unsigned long D) : Quadrilateral(a, b, c, d, A, B, C, D)//�����������
    {
        name = "����";
        if (a == b && b == c && c == d && A == C && B == D)//�������� ������������ ��������� ������
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        else
        {
            isCorrect = false;
        }
    }
};

void print_info(Figure* figure)//������ � �������
{
    figure->print();
}

void createFigure(Figure& typeOfFigure)//����� � ��� ������� ���������� �������� �� �������� ������
{
    std::cout << typeOfFigure.getName() << ":" << std::endl;
    if (!typeOfFigure.getISCorrect())
    {
        std::cout << "������ � ������ ����������� ������� ������" << std::endl << std::endl;
    }
    else
    {
        Figure* figure = &typeOfFigure;
        print_info(figure);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //�����������
    Triangle triangle(10, 20, 30, 50, 60, 70);
    createFigure(triangle);

    //������������� �����������
    RightTriangle rightTriangle(10, 20, 30, 50, 60, 90);
    createFigure(rightTriangle);

    //�������������� �����������
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 50);
    createFigure(isoscelesTriangle);

    //�������������� �����������
    EquilateralTriangle equilateralTriangle(30, 30, 30, 60, 60, 60);
    createFigure(equilateralTriangle);

    //���������������
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    createFigure(quadrilateral);

    //�������������
    RectangleThis rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    createFigure(rectangle);

    //�������
    Square square(10, 10, 10, 10, 90, 90, 90, 90);
    createFigure(square);

    //��������������
    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    createFigure(parallelogram);

    //����
    Rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);
    createFigure(rhomb);

    return 0;
}