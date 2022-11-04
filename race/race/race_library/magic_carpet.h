#pragma once

#include "air_transport.h"

namespace race
{
	class MagicCarpet : public AirTransport
	{
	public:
		MagicCarpet();
		void timeCalculation(int distance) override;
	};
}
