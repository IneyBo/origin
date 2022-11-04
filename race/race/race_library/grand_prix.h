#pragma once

#include "transport.h"

namespace race
{
	class GrandPrix // Класс Гонка
	{
	protected:
		std::string nameOfGrandPrix; // Название гонки (воздушная, наземная, смешанная)
		bool isAirGrandPrix; // Воздушная ли гонка
		int numberOfMembers; // Количество участников
		Transport* arrOfMembers[7]; // Массив с участниками
	public:
		GrandPrix();
		virtual void addTransport(Transport &member); // Добавление участника
		std::string getNameOfGrandPrix();
		bool getIsAirGrandPrix(); // Получение воздушная ли гонка
		int getNumberOfMembers() const; // Получение количества участников
		Transport getMember(int number); // Получение транспорта из заявленных
		void conductGrandPrix(int distance); // Проведение гонки
		void sortMembers(); // Сортировка участников 
	};
}
