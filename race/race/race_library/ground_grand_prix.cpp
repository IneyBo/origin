#include "ground_grand_prix.h"
#include "grand_prix_error.h"

namespace race
{
	GroundGrandPrix::GroundGrandPrix() : GrandPrix()
	{
		nameOfGrandPrix = "Гонка для наземного транспорта";
		isAirGrandPrix = false;
	}
	void GroundGrandPrix::addTransport(Transport& member)
	{
		if (numberOfMembers > 0) // Проверка, есть ли такой уже зарегистрированный транспорт
		{
			for (int i = 0; i < numberOfMembers; ++i)
			{
				if (member.getName() == arrOfMembers[i]->getName())
				{
					throw GrandPrixError(member.getName() + " уже зарегистрирован!");
				}
			}
		}
		if (member.getIsAir()) // Проверка на вид транспорта
		{
			throw GrandPrixError("Попытка зарегистрировать неправильный тип траснпортного средства");
		}
		else
		{
			++numberOfMembers;
			arrOfMembers[numberOfMembers - 1] = &member;
		}
	}
}