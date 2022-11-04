#include "speed_camel.h"

namespace race
{
	SpeedCamel::SpeedCamel() : GroundTransport()
	{
		name = "Верблюд-быстроход";
		speed = 40;
		timeBeforeRest = 10;
		raceDuration1 = 5;
		raceDuration2 = 6.5;
		raceDurationNext = 8;
	}
	void SpeedCamel::timeCalculation(int distance)
	{
		if (distance < speed * timeBeforeRest)
		{
			time = static_cast<double>((distance / speed));
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 2)
		{
			time = static_cast<double>((distance / speed) + raceDuration1);
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 3)
		{
			time = static_cast<double>((distance / speed) + raceDuration2);
		}
		else if (distance >= speed * timeBeforeRest * 3)
		{
			time = static_cast<double>((distance / speed) + raceDuration1 + raceDuration2 + ((distance) / (speed * timeBeforeRest) * raceDurationNext));
		}
	}
}