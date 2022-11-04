#pragma once

#include "grand_prix.h"

namespace race
{
	class AirGrandPrix : public GrandPrix // Класс  воздушных гонок
	{
	public:
		AirGrandPrix();
		void addTransport(Transport& member) override; // Добавление участника
	};
}
