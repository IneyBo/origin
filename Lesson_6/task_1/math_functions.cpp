#include "math_functions.h"

double addition (double x, double y)
{
	return x + y;
}

double substraction(double x, double y)
{
	return x - y;
}

double multiplication(double x, double y)
{
	return x * y;
}

double division(double x, double y)
{
	return x / y;
}

double power(double x, double y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x;
	}
	else
	{
		double result = x;
		for (int i = 2; i <= y; ++i)
		{
			result = result * x;
		}
		return result;
	}
}