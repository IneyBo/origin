#include "eagle.h"

namespace race
{
	Eagle::Eagle() : AirTransport()
	{
		name = "Орел";
		speed = 8;
		distanceReductionCoefficient = 0,06;
	}
	void Eagle::timeCalculation(int distance)
	{
		time = distance / ((1 - distanceReductionCoefficient) * speed);
	}
}