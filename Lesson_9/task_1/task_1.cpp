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
	int greatestCommonDivisor(int x_, int y_) // Наибольший общий делитель
	{
		int x = abs(x_);
		int y = abs(y_);

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
	int leastCommonMultiple(int denominator) // Наименьшее общее кратное
	{
		return (denominator_ * denominator) / greatestCommonDivisor(numerator_, denominator);
	}
	bool operator==(Fraction fraction)
	{
		return (fraction.numerator_ * this->denominator_ == this->numerator_ * fraction.denominator_);
	}
	bool operator!=(Fraction fraction)
	{
		return !(*this == fraction);
	}
	// Так как сравнивать числа с плавающей запятой нельзя, решил сделать сравнение через числители дробей, приведенных к общему знаменателю
	bool operator<(Fraction fraction)
	{
		int least_common_multiple = leastCommonMultiple(fraction.denominator_); // Наименьшее общее кратное для числителя и знаменателя

		int additionalMultiplier1 = least_common_multiple / denominator_; // Дополнительный множитель для первого числителя
		int additionalMultiplier2 = least_common_multiple / fraction.denominator_; // Дополнительный множитель для второго числителя

		int numerator1 = additionalMultiplier1 * numerator_; // Итоговый первый числитель

		int numerator2 = additionalMultiplier2 * fraction.numerator_; // Итоговый второй  числитель

		return (numerator1 < numerator2);
	}
	bool operator>(Fraction fraction)
	{
		return (fraction < *this);
	}
	bool operator<=(Fraction fraction)
	{
		return !(*this > fraction);
	}
	bool operator>=(Fraction fraction)
	{
		return !(*this < fraction);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}