#include "broom.h"

namespace race
{
	Broom::Broom() : AirTransport()
	{
		name = "Метла";
		speed = 20;
		distanceReductionCoefficient = 0;
	}
	void Broom::timeCalculation(int distance)
	{
		if (distance < 1000)
		{
			distanceReductionCoefficient = 0;
		}
		else if (distance >= 1000)
		{
			distanceReductionCoefficient = (distance / 1000) * 0.01;
		}
		time = distance / ((1 - distanceReductionCoefficient) * speed);
	}
}