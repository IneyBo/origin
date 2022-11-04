#include "mixed_grand_prix.h"
#include "grand_prix_error.h"

namespace race
{
	MixedGrandPrix::MixedGrandPrix() : GrandPrix()
	{
		nameOfGrandPrix = "Гонка для наземного т воздушного транспорта";
	}
	void MixedGrandPrix::addTransport(Transport& member)
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
		++numberOfMembers;
		arrOfMembers[numberOfMembers - 1] = &member;
	}
}