#include <iostream>

#include "triangle.h"

Triangle::Triangle(unsigned long a, unsigned long b, unsigned long c, unsigned long A, unsigned long B, unsigned long C) : Figure() // �����������
{
    numberOfSides = 3;
    name = "�����������";
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    //isCorrect = ((A + B + C) == 180) ? true : false; //�������� ������������ ��������� ������
}

// �������
unsigned long Triangle::get_a() const
{
    return a;
}
unsigned long Triangle::get_b() const
{
    return b;
}
unsigned long Triangle::get_c() const
{
    return c;
}
unsigned long Triangle::get_A() const
{
    return A;
}
unsigned long Triangle::get_B() const
{
    return B;
}
unsigned long Triangle::get_C() const
{
    return C;
}

bool Triangle::isCorrect()
{
    return ((A + B + C) == 180) ? true : false;
}

void Triangle::print() // ����� � �������
{
    std::cout << name << ":" << std::endl << (isCorrect() ? "����������" : "������������") << std::endl << "���������� ������: " << numberOfSides << std::endl << "�������: a=" << a << " b=" << b << " c=" << c << std::endl
        << "����: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}