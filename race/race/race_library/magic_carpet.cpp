#include "magic_carpet.h"

namespace race
{
	MagicCarpet::MagicCarpet() : AirTransport()
	{
		name = "Ковер-самолет";
		speed = 10;
		distanceReductionCoefficient = 0;
	}
	void MagicCarpet::timeCalculation(int distance)
	{
		if (distance < 1000)
		{
			distanceReductionCoefficient = 0;
		}
		else if (distance >= 1000 && distance < 5000)
		{
			distanceReductionCoefficient = 0.03;
		}
		else if (distance >= 5000 && distance < 10000)
		{
			distanceReductionCoefficient = 0.1;
		}
		else if (distance >= 10000)
		{
			distanceReductionCoefficient = 0.05;
		}
		time = (distance * (1 - distanceReductionCoefficient)) / speed;
	}
}