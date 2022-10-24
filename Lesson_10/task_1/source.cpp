#include <iostream>

#include <Windows.h>

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите имя: ";

	std::string name = "_";

	std::cin >> name;
	std::cout << "Здравствуйте, " << name;

	return 0;
}