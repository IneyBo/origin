#include "terrain_boots.h"

namespace race
{
	TerrainBoots::TerrainBoots() : GroundTransport()
	{
		name = "Ботинки-вездеходы";
		speed = 6;
		timeBeforeRest = 60;
		raceDuration1 = 10;
		raceDuration2 = 0;
		raceDurationNext = 5;
	}
	void TerrainBoots::timeCalculation(int distance)
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