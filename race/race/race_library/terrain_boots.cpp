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
		if (distance < speed * timeBeforeRest) // До первого отдыха
		{
			time = static_cast<double>(distance) / static_cast<double>(speed);
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 2) // После первого отдыха
		{
			time = ((static_cast<double>(distance) / static_cast<double>(speed)) + raceDuration1);
		}
		else if (distance >= speed * timeBeforeRest * 2) // После последующих отдыхов
		{
			if (distance % (speed * timeBeforeRest) == 0) // Если общее время приходится на очередную остановку, то она не защитывается
			{
				time = (static_cast<double>(distance) / static_cast<double>(speed))
					+ raceDuration1
					+ static_cast<double>(((distance / speed) / timeBeforeRest) - 2) * raceDurationNext;
			}
			else
			{
				time = (static_cast<double>(distance) / static_cast<double>(speed))
					+ raceDuration1
					+ static_cast<double>(((distance / speed) / timeBeforeRest) - 1) * raceDurationNext;
			}
		}
	}
}