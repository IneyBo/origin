#include "air_grand_prix.h"
#include "grand_prix_error.h"

namespace race
{
	AirGrandPrix::AirGrandPrix() : GrandPrix()
	{
		nameOfGrandPrix = "Гонка для воздушного транспорта";
		isAirGrandPrix = true;
	}
	void AirGrandPrix::addTransport(Transport& member)
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
		if (!member.getIsAir()) // Проверка на вид траснпорта
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