#include "air_transport.h"

namespace race
{
	AirTransport::AirTransport() : Transport()
	{
		isAir = true;
		distanceReductionCoefficient = 0;
	}
}