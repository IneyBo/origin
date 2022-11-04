#include "centaur.h"

namespace race
{
	Centaur::Centaur() : GroundTransport()
	{
		name = "Кентавр";
		speed = 15;
		timeBeforeRest = 8;
		raceDuration1 = 0;
		raceDuration2 = 0;
		raceDurationNext = 2;
	}
	void Centaur::timeCalculation(int distance)
	{
		if (distance < speed * timeBeforeRest)
		{
			time = static_cast<double>((distance / speed));
		}
		else if (distance >= speed * timeBeforeRest)
		{
			time = static_cast<double>((distance / speed) + ((distance) / (speed * timeBeforeRest) * raceDurationNext));
		}
	}
}