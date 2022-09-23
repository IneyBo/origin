#include <windows.h>

#include <iostream>
#include <fstream>

class Address // Класс для работы с адресом
{
private:
    std::string city;
    std::string street;
    unsigned short house;
    unsigned short flat;
public:
    Address() // Конструктор без параметров
    {
        city = "неизвестно";
        street = "неизвестно";
        house = 0;
        flat = 0;
    }

    void setAddress(std::ifstream& value) // Сеттер
    {
        value >> city;
        value >> street;
        value >> house;
        value >> flat;
    }

    // Геттеры
    std::string getCity() const
    {
        return city;
    }
    std::string getStreet() const
    {
        return street;
    }
    unsigned short getHouse() const
    {
        return house;
    }
    unsigned short getFlat() const
    {
        return flat;
    }
};

class AddressConverter // Класс для работы с массивами адресов, чтения и записи файлов
{
private:
    int size = 0;
    Address* arrOfAddresses = nullptr;
public:
    void fillArrOfAddresses(std::ifstream& fin) // Заполнение массива адресов
    {
        fin >> size;
        if (size != 0)
        {
            arrOfAddresses = new Address[size];
            for (int i = 0; i < size; ++i)
            {
                arrOfAddresses[i].setAddress(fin);
            }
        }
    }
    void outReverseArrOfAddresses(std::ofstream& fout) // Вывод в файл массива адресов в обратном порядке
    {
        fout << size;
        if (size != 0)
        {
            for (int i = size - 1; i >= 0 ; --i)
            {
                fout << std::endl << arrOfAddresses[i].getCity() << ", " << arrOfAddresses[i].getStreet() << ", " << arrOfAddresses[i].getHouse() << ", " << arrOfAddresses[i].getFlat();
            }
            delete[] arrOfAddresses;
            arrOfAddresses = nullptr;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string fileIn = "in.txt", fileOut = "out.txt";
    std::ifstream fin(fileIn);

    if (!fin.is_open())
    {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    else
    {
        AddressConverter setOfAddresses;
        setOfAddresses.fillArrOfAddresses(fin);

        fin.close();

        std::ofstream fout(fileOut);

        setOfAddresses.outReverseArrOfAddresses(fout);

        fout.close();
    }
    return 0;
}