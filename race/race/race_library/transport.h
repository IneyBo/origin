#pragma once

#include <string>

namespace race
{
	class Transport
	{
	protected:
		bool isAir; // Воздушный ли транспорт
		std::string name;
		double time;
		int speed;
	public:
		Transport(); // Конструктор
		bool getIsAir(); // Получение воздушный ли транспорт
		double getTime(); // Получение времени
		std::string getName(); // Получение имени
		int getSpeed(); // Получение скорости
		virtual void timeCalculation(int distance); // Расчет времени
	};
}
