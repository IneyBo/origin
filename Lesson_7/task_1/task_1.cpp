#include <Windows.h>

#include <iostream>

#define MODE 1
#ifndef MODE
#error Important MODE required
#endif // MODE

#if MODE == 1
int add(int a, int b)
{
    return a + b;
}
#endif

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if MODE == 0
std::cout << "������� � ������ ����������" << std::endl;
#elif MODE == 1
    int a, b;
std::cout << "������� � ������ ������" << std::endl;
std::cout << "������� �����: ";
std::cin >> a;
std::cout << "������� �����: ";
std::cin >> b;
std::cout << "��������� ��������: " << add(a, b) << std::endl;
#else
std::cout << "����������� �����. ���������� ������" << std::endl;
#endif
}