#pragma once

#include "ground_transport.h"

namespace race
{
	class Camel : public GroundTransport
	{
	public:
		Camel();
		void timeCalculation(int distance) override;
	};
}