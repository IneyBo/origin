#pragma once

#include "grand_prix.h"

namespace race
{
	class GroundGrandPrix : public GrandPrix // Класс наземных гонок
	{
	public:
		GroundGrandPrix();
		void addTransport(Transport& member) override; // Добавление участника
	};
}
