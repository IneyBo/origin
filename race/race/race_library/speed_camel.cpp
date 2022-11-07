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
		if (distance < speed * timeBeforeRest) // До первого отдыха
		{
			time = static_cast<double>(distance) / static_cast<double>(speed);
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 2) // После первого отдыха
		{
			time = ((static_cast<double>(distance) / static_cast<double>(speed)) + raceDuration1);
		}
		else if (distance >= speed * timeBeforeRest && distance < speed * timeBeforeRest * 3) // После второго отдыха
		{
			time = (static_cast<double>(distance) / static_cast<double>(speed) + raceDuration1 + raceDuration2); // После последующих отдыхов
		}
		else if (distance >= speed * timeBeforeRest * 3)
		{
			if (distance % (speed * timeBeforeRest) == 0) // Если общее время приходится на очередную остановку, то она не защитывается
			{
				time = (static_cast<double>(distance) / static_cast<double>(speed))
					+ raceDuration1
					+ raceDuration2
					+ static_cast<double>(((distance / speed) / timeBeforeRest) - 2) * raceDurationNext;
			}
			else
			{
				time = (static_cast<double>(distance) / static_cast<double>(speed))
					+ raceDuration1
					+ raceDuration2
					+ static_cast<double>(((distance / speed) / timeBeforeRest) - 1) * raceDurationNext;
			}
		}
	}
}