#include "transport.h"

namespace race
{
	Transport::Transport() // Класс транспорт
	{
		isAir = false;
		time = 0;
		speed = 0;
	}

	//Геттеры

	bool Transport::getIsAir()
	{
		return isAir;
	}
	double Transport::getTime()
	{
		return time;
	}

	std::string Transport::getName()
	{
		return name;
	}

	int Transport::getSpeed()
	{
		return speed;
	}

	void Transport::timeCalculation(int distance)
	{
	}
}