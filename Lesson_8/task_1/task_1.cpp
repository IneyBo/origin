#include <Windows.h>

#include <iostream>

class bad_lenght : public std::exception
{
public:
    const char* what() const override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_lenght)
{
    if (str.size() == forbidden_lenght) throw bad_lenght();
    return str.size();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int forbidden_length = 0;
    std::string input_word = "_";

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    while (input_word.size() != forbidden_length)
    {
        std::cout << "Введите слово: ";
        std::cin >> input_word;
        try
        {
            std::cout << "Длина слова \"" << input_word << "\" равна " << function(input_word, forbidden_length) << std::endl;
        }
        catch (const bad_lenght& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "Неизвестная ошибка" << std::endl;
        }
    }
}