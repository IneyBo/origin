#pragma once

#include "air_transport.h"

namespace race
{
	class Broom : public AirTransport // Класс Метла
	{
	public:
		Broom();
		void timeCalculation(int distance) override;
	};
}