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
std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    int a, b;
std::cout << "Работаю в боевом режиме" << std::endl;
std::cout << "Введите число: ";
std::cin >> a;
std::cout << "Введите число: ";
std::cin >> b;
std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
}