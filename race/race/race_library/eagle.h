#pragma once

#include "air_transport.h"

namespace race
{
	class Eagle : public AirTransport
	{
	public:
		Eagle();
		void timeCalculation(int distance) override;
	};
}