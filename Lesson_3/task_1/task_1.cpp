#include <iostream>

class Calculator
{
private:
    double num1;
    double num2;
public:
    double get_num1()
    {
        return num1;
    }

    double get_num2()
    {
        return num2;
    }

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double substract_1_2()
    {
        return num1 - num2;
    }

    double substract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }

    bool set_num1(double num1)
    {
        if (num1 != 0)
        {
            this->num1 = num1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 != 0)
        {
            this->num2 = num2;
            return true;
        }
        else
        {
            return false;
        }
    }
};

void printCalc(Calculator calc)
{
    std::cout << "num1 + num2 = " << calc.add() << std::endl;
    std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
    std::cout << "num1 - num2 = " << calc.substract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << calc.substract_2_1() << std::endl;
    std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double num1 = 0;
    double num2 = 0;

    while (true)
    {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        std::cout << "Введите num2: ";
        std::cin >> num2;

        Calculator calc;
        
        if (!calc.set_num1(num1) || !calc.set_num2(num2))
        {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        printCalc(calc);
    }

}