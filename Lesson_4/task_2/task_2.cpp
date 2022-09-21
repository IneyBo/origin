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
    std::string getCity()
    {
        return city;
    }
    std::string getStreet()
    {
        return street;
    }
    unsigned short getHouse()
    {
        return house;
    }
    unsigned short getFlat()
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
    int getSize()
    {
        return size;
    }
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
    void sortArrOfAddresses() // Сортировка массива
    {
        bool swapped = false;
        do
        {
            swapped = false;
            for (int i = 1; i < size; ++i) // иду по массиву от начала до конца
            {
                if (arrOfAddresses[i - 1].getCity() > arrOfAddresses[i].getCity())
                {
                    Address temp = arrOfAddresses[i];
                    arrOfAddresses[i] = arrOfAddresses[i - 1];
                    arrOfAddresses[i - 1] = temp;
                    swapped = true;
                }
            }
        } while (swapped);
    }
    void outForwardArrOfAddresses(std::ofstream& fout) // Вывод в файл массива адресов
    {
        fout << size;
        if (size != 0)
        {
            for (int i = 0; i < size; ++i)
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

        if (setOfAddresses.getSize() > 0)
        {
            setOfAddresses.sortArrOfAddresses();
        }

        setOfAddresses.outForwardArrOfAddresses(fout);

        fout.close();
    }
    return 0;
}