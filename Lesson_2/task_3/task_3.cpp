#include <iostream>
#include <Windows.h>

struct Address
{
    std::string m_country;
    std::string m_city;
    std::string m_street;
    unsigned short m_house;
    unsigned short m_flat;
    unsigned long m_index;
};

void printAddress(Address& addrress)
{
    std::cout << "Страна: " << addrress.m_country << std::endl;
    std::cout << "Город: " << addrress.m_city << std::endl;
    std::cout << "Улица: " << addrress.m_street << std::endl;
    std::cout << "Номер дома: " << addrress.m_house << std::endl;
    std::cout << "Номер квартиры: " << addrress.m_flat << std::endl;
    std::cout << "Индекс: " << addrress.m_index << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Address address1 =
    {
        "Россия",
        "Москва",
        "Арбат",
        12,
        8,
        123456
    };

    Address address2 =
    {
        "Россия",
        "Ижевск",
        "Пушкина",
        59,
        143,
        953769
    };

    printAddress(address1);
    std::cout << std::endl;
    printAddress(address2);

    return 0;
}
