#include "camel.h"

namespace race
{
	Camel::Camel() : GroundTransport()
	{
		name = "Верблюд";
		speed = 10;
		timeBeforeRest = 30;
		raceDuration1 = 5;
		raceDuration2 = 0;
		raceDurationNext = 8;
	}
	void Camel::timeCalculation(int distance)
	{
		if (distance < speed * timeBeforeRest)
		{
			time = static_cast<double>((distance / speed));
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 2)
		{
			time = static_cast<double>((distance / speed) + raceDuration1);
		}
		else if (distance >= speed * timeBeforeRest * 2)
		{
			time = static_cast<double>((distance / speed) + raceDuration1 + ((distance) / (speed * timeBeforeRest) * raceDurationNext));
		}
	}
}