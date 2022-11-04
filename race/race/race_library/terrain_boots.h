#pragma once

#include "ground_transport.h"

namespace race
{
	class TerrainBoots : public GroundTransport
	{
	public:
		TerrainBoots();
		void timeCalculation(int distance) override;
	};
}