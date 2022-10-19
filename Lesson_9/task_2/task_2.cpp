#include <Windows.h>
#include <iostream>
#include <cmath>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int getNumerator_()
	{
		return numerator_;
	}
	int getDenominator_()
	{
		return denominator_;
	}
	int greatestCommonDivisor(int x_, int y_) // Наибольший общий делитель. Используетсмя как для сложения-вычитания дробей, так и для сокращения дробей
	{
		int x = abs(x_);
		int y = abs(y_);

		if (x_ == 0 || y_ == 0)
		{
			return 1;
		}
		else
		{
			while (x != y) {
				if (x > y) {
					x = x - y;
				}
				else {
					y = y - x;
				}
			}
			return x;
		}
	}
	int leastCommonMultiple(int denominator) // Наименьшее общее кратное
	{		
		return (denominator_ * denominator) / greatestCommonDivisor(denominator_, denominator);
		//return (denominator_ * denominator) / greatestCommonDivisor(numerator_, denominator);
	}
	Fraction operator+(Fraction other)
	{
		int least_common_multiple = leastCommonMultiple(other.denominator_); // Наименьшее общее кратное знаменателей двух дробей

		int additionalMultiplier1 = least_common_multiple / denominator_; // Дополнительный множитель для первого числителя
		int additionalMultiplier2 = least_common_multiple / other.denominator_; // Дополнительный множитель для второго числителя

		int numerator = (additionalMultiplier1 * numerator_) + (additionalMultiplier2 * other.numerator_); // Итоговый числитель

		int greatest_common_divisor = greatestCommonDivisor(numerator, least_common_multiple); // Наибольший общий делитель для итоговой дроби
		
		return Fraction((numerator / greatest_common_divisor), (least_common_multiple / greatest_common_divisor));
	}
	Fraction operator-(Fraction other)
	{
		int least_common_multiple = leastCommonMultiple(other.denominator_); // Наименьшее общее кратное знаменателей двух дробей

		int additionalMultiplier1 = least_common_multiple / denominator_; // Дополнительный множитель для первого числителя
		int additionalMultiplier2 = least_common_multiple / other.denominator_; // Дополнительный множитель для второго числителя

		int numerator = (additionalMultiplier1 * numerator_) - (additionalMultiplier2 * other.numerator_); // Итоговый числитель

		int greatest_common_divisor = greatestCommonDivisor(numerator, least_common_multiple); // Наибольший общий делитель для итоговой дроби

		return Fraction((numerator / greatest_common_divisor), (least_common_multiple / greatest_common_divisor));
	}
	Fraction operator*(Fraction other)
	{
		int numerator = numerator_ * other.numerator_;
		int denominator = denominator_ * other.denominator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator, denominator); // Наибольший общий делитель для итоговой дроби

		return Fraction((numerator / greatest_common_divisor), (denominator / greatest_common_divisor));
	}
	Fraction operator/(Fraction other)
	{
		int numerator = numerator_ * other.denominator_;
		int denominator = denominator_ * other.numerator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator, denominator); // Наибольший общий делитель для итоговой дроби

		return Fraction((numerator / greatest_common_divisor), (denominator / greatest_common_divisor));
	}
	Fraction operator-()
	{
		return Fraction(numerator_ * (-1), denominator_);
	}
	Fraction operator++()
	{
		numerator_ = numerator_ + denominator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator_, denominator_); // Наибольший общий делитель для итоговой дроби
		
		return Fraction((numerator_ / greatest_common_divisor), (denominator_ / greatest_common_divisor));
	}
	Fraction operator++(int)
	{
		return Fraction(numerator_, denominator_);

		numerator_ = numerator_ + denominator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator_, denominator_); // Наибольший общий делитель для итоговой дроби

		numerator_ = numerator_ / greatest_common_divisor;
		denominator_ = denominator_ / greatest_common_divisor;
	}
	Fraction operator--()
	{
		numerator_ = numerator_ - denominator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator_, denominator_); // Наибольший общий делитель для итоговой дроби

		return Fraction((numerator_ / greatest_common_divisor), (denominator_ / greatest_common_divisor));
	}
	Fraction operator--(int)
	{
		int tempNumerator = numerator_;

		numerator_ = numerator_ - denominator_;

		int greatest_common_divisor = greatestCommonDivisor(numerator_, denominator_); // Наибольший общий делитель для итоговой дроби

		numerator_ = numerator_ / greatest_common_divisor;
		denominator_ = denominator_ / greatest_common_divisor;
		
		return Fraction(tempNumerator, denominator_);
	}
};

void print(Fraction fraction)
{
	if (fraction.getNumerator_() != 0)
	{
		std::cout << fraction.getNumerator_() << "/" << fraction.getDenominator_() << std::endl;
	}
	else
	{
		std::cout << "0" << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numerator1, numerator2, denominator1, denominator2;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);

	std::cout << numerator1 << "/" << denominator1 << " + " << numerator2 << "/" << denominator2 << " = ";
	print(f1 + f2);

	std::cout << numerator1 << "/" << denominator1 << " - " << numerator2 << "/" << denominator2 << " = ";
	print(f1 - f2);

	std::cout << numerator1 << "/" << denominator1 << " * " << numerator2 << "/" << denominator2 << " = ";
	print(f1 * f2);

	std::cout << numerator1 << "/" << denominator1 << " / " << numerator2 << "/" << denominator2 << " = ";
	print(f1 / f2);

	std::cout << "--" << numerator1 << "/" << denominator1 << " * " << numerator2 << "/" << denominator2 << " = ";
	print(--f1 * f2);
	std::cout << "Значение дроби 1 = ";
	print(f1);

	std::cout << numerator1 << "/" << denominator1 << "++ * " << numerator2 << "/" << denominator2 << " = ";
	print(f1++ * f2);
	std::cout << "Значение дроби 1 = ";
	print(f1);

	return 0;
}