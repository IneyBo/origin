#pragma once

#include "ground_transport.h"

namespace race
{
	class Centaur : public GroundTransport
	{
	public:
		Centaur();
		void timeCalculation(int distance) override;
	};
}
