#include "ground_transport.h"

namespace race
{
	GroundTransport::GroundTransport() : Transport()
	{
		isAir = false;
		timeBeforeRest = 0;
		raceDuration1 = 0;
		raceDuration2 = 0;
		raceDurationNext = 0;
	};
}