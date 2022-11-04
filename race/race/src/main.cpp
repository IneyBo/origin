#include <iostream>
#include <limits>

#include <Windows.h>

#include "leaver.h"
#include "transport.h"
#include "ground_transport.h"
#include "air_transport.h"
#include "camel.h"
#include "centaur.h"
#include "speed_camel.h"
#include "terrain_boots.h"
#include "magic_carpet.h"
#include "eagle.h"
#include "broom.h"
#include "grand_prix.h"
#include "ground_grand_prix.h"
#include "air_grand_prix.h"
#include "mixed_grand_prix.h"
#include "grand_prix_error.h"

int checkInput() // Проверка на вводимые данные
{
    int input = 0;
    while (!(std::cin >> input) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Неверный ввод. Введите корректные данные: ";
    }
    return input;
}

void printResult(race::GrandPrix* grandPrix) // Печать результатов гонки
{
    std::cout << "Результаты гонки:" << std::endl;
    for (int i = 0; i < grandPrix->getNumberOfMembers(); ++i)
    {
        std::cout << grandPrix->getMember(i).getName() << ". Время: " << grandPrix->getMember(i).getTime() << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool startApp = true; // Переменная для повторного запуска приложения

    while (startApp)
    {
        // Гонка
        race::GrandPrix* grandPrix;
        // Подвиды гонок
        race::GroundGrandPrix groundGrandPrix;
        race::AirGrandPrix airGrandPrix;
        race::MixedGrandPrix mixedGrandPrix;
        // Выбираем транспорт на гонку
        race::Camel camel;
        race::SpeedCamel speedCamel;
        race::Centaur centaur;
        race::TerrainBoots terrainBoots;
        race::MagicCarpet magicCarpet;
        race::Eagle eagle;
        race::Broom broom;

        /* Начальное меню */
        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl
            << "1. Гонка для наземного транспорта" << std::endl
            << "2. Гонка для воздушного транспорта" << std::endl
            << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        /* Меню выбора гонки */
        // Выбор типа гонки
        int input = 0;
        while (input != 1 && input != 2 && input != 3)
        {
            std::cout << "Выберите тип гонки: ";
            input = checkInput();
            if (input != 1 && input != 2 && input != 3)
            {
                std::cout << "Введите корректные данные" << std::endl;
            }
        }

        // Назначение типа гонки
        switch (input)
        {
        case 1:
            grandPrix = &groundGrandPrix;
            break;
        case 2:
            grandPrix = &airGrandPrix;
            break;
        case 3:
            grandPrix = &mixedGrandPrix;
            break;
        default:
            break;
        }

        /* Меню ввода дистанции */
        int distance = 0;
        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        do
        {
            distance = checkInput();
            if (distance <= 0)
            {
                std::cout << "Введите положительную длину дистанции" << std::endl;
            }
        } while (distance < 0);

        /* Предменю регистрации */
        std::cout << "должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl
                << "1. Зарегистрировать транспорт" << std::endl
                << "Выберите действие: ";
        do
        {
            input = checkInput();
            if (input != 1)
            {
                std::cout << "Введите 1: ";
            }
        } while (input != 1);

        /* Меню регистрации */
        bool exit = false; // Переменная для выхода из цикла меню регистрации
        do
        {
            // Печатаем тип гонки и дистанцию
            std::cout << grandPrix->getNameOfGrandPrix() << ". Расстояние: " << distance << std::endl;

            // Печатаем зарегистрированный транспорт, если есть на данный момент
            if (grandPrix->getNumberOfMembers() > 0)
            {
                std::cout << "Зарегистрированные транспортные средства: ";
                for (int i = 0; i < grandPrix->getNumberOfMembers(); ++i)
                {
                    if (i == 0)
                    {
                        std::cout << grandPrix->getMember(i).getName();
                    }
                    else if (i > 0)
                    {
                        std::cout << ", " << grandPrix->getMember(i).getName();
                    }
                }
                std::cout << std::endl;
            }

            // Печатаем список транспорта
            std::cout << "1. Ботинки-вездеходы\n2. Метла\n3. Верблюд\n4. Кентавр\n5. Орел\n6. Верблюд-быстроход\n7. Ковер-самолет\n0. Закончить регистрацию\nВыберите транспорт или 0 для окончания процесса регистрации: ";

            // Ввод значений
            do
            {
                input = checkInput();
                if (input < 0 || input > 7)
                {
                    std::cout << "Введите корректные данные: ";
                }
            } while (input < 0 || input > 7);

            if (input == 0 && grandPrix->getNumberOfMembers() < 2) // Если меньше двух участников
            {
                std::cout << "Дожно быть зарегистрировано хотя бы 2 участника. Зарегистрируйте еще транспортное средство" << std:: endl;
            }
            else if (input == 0 && grandPrix->getNumberOfMembers() >= 2) // Условие захода в подменю «начать гонку или вернуться обратно»
            {
                int input2 = 0;
                std::cout << "1. Зарегистрировать транспорт\n2. Начать гонку\nВыберите действие: ";
                std::cin >> input2;
                if (input2 == 2) // Условие выхода из меню регистрации
                {
                    exit = true;
                }
            }
            else if (input > 0 && input <= 7) // Если введены корректные данные
            {
                bool registration = true; // Переменная для опредления, удалось ли зарегистрировать транспорт
                try
                {
                    switch (input)
                    {
                    case 1:
                        grandPrix->addTransport(terrainBoots);
                        break;
                    case 2:
                        grandPrix->addTransport(broom);
                        break;
                    case 3:
                        grandPrix->addTransport(camel);
                        break;
                    case 4:
                        grandPrix->addTransport(centaur);
                        break;
                    case 5:
                        grandPrix->addTransport(eagle);
                        break;
                    case 6:
                        grandPrix->addTransport(speedCamel);
                        break;
                    case 7:
                        grandPrix->addTransport(magicCarpet);
                        break;
                    default:
                        break;
                    }
                }
                catch (race::GrandPrixError ex)
                {
                    std::cout << ex.what() << std::endl;
                    registration = false;
                }

                if (registration) // Если транспорт зарегистрирован, то выводим сообщение
                {
                    std::cout << grandPrix->getMember(grandPrix->getNumberOfMembers() - 1).getName() << " успешно зарегистрирован!" << std::endl;
                }
            }
        } while (exit == false);

        grandPrix->conductGrandPrix(distance); // Проведение гонки (расчет времени)
        grandPrix->sortMembers(); // Сортировка участников
        printResult(grandPrix); // Печать результатов гонки

        /* Меню выхода */
        std::cout << "1. Провести еще одну гонку\n2. Выйти\nВыберите действие: ";
        do
        {
            input = checkInput();
            if (input != 1 && input != 2)
            {
                std::cout << "Введите корректные данные: ";
            }
            else if (input == 2)
            {
                startApp = false;
            }
        } while (input != 1 && input != 2);
    }

    return 0;
}