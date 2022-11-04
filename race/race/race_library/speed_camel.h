#pragma once

#include "ground_transport.h"

namespace race
{
	class SpeedCamel : public GroundTransport
	{
	public:
		SpeedCamel();
		void timeCalculation(int distance) override;
	};
}