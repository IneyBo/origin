#include <Windows.h>
#include <iostream>

struct BankAccount
{
    unsigned long long m_numberOfAccount;
    std::string m_name;
    float m_amountMoney;
};

void changeAmountMoney (BankAccount& account, float amountMoney)
{
    account.m_amountMoney = amountMoney;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankAccount account;
    std::cout << "Введите номер счета: ";
    std::cin >> account.m_numberOfAccount;
    std::cout << "Введите Имя владельца: ";
    std::cin >> account.m_name;
    std::cout << "Введите баланс: ";
    std::cin >> account.m_amountMoney;

    float amountMoney = 0;

    std::cout << "Введите новый баланс: ";
    std::cin >> amountMoney;

    changeAmountMoney(account, amountMoney);

    std::cout << "Ваш счет: " << account.m_name << ", " << account.m_numberOfAccount << ", " << account.m_amountMoney;

    return 0;
}