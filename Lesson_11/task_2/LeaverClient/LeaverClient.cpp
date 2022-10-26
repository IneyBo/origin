#include <iostream>

#include <Windows.h>

#include "../LeaverLibraryDynamic/leaver.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Communication::Leaver leaving;
    std::cout << "¬ведите им€: ";
    std::string inputWord;
    std::cin >> inputWord;
    std::cout << leaving.leave(inputWord) << std::endl;

    return 0;
}