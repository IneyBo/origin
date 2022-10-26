#include <iostream>

#include <Windows.h>

#include "../GreeterLibraryStatic/greeter.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Communication::Greeter greeting;
    std::cout << "¬ведите им€: ";
    std::string inputWord;
    std::cin >> inputWord;
    std::cout << greeting.greet(inputWord) << std::endl;

    return 0;
}