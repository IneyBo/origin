#pragma once

#include "transport.h"

namespace race
{
	class AirTransport : public Transport // Класс воздушный транспорт
	{
	protected:
		double distanceReductionCoefficient;
	public:
		AirTransport();
	};
}
