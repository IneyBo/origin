#pragma once

#include "grand_prix.h"

namespace race
{
	class MixedGrandPrix : public GrandPrix // Класс смешанных гонок
	{
	public:
		MixedGrandPrix();
		void addTransport(Transport& member) override;
	};
}
