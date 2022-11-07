#include "grand_prix.h"

namespace race
{
	GrandPrix::GrandPrix() //: arrOfMembers {&Transport()}
	{
		nameOfGrandPrix = "Неопределено";
		isAirGrandPrix = false;
		*arrOfMembers = { &Transport() };
		numberOfMembers = 0;
	}

	void GrandPrix::addTransport(Transport& member)
	{
		++numberOfMembers;
		arrOfMembers[numberOfMembers - 1] = &member;
	}

	std::string GrandPrix::getNameOfGrandPrix()
	{
		return nameOfGrandPrix;
	}
	int GrandPrix::getNumberOfMembers() const
	{
		return numberOfMembers;
	}
	Transport GrandPrix::getMember(int number)
	{
		return *arrOfMembers[number];
	}
	void GrandPrix::conductGrandPrix(int distance)
	{
		for (int i = 0; i < numberOfMembers; ++i)
		{
			arrOfMembers[i]->timeCalculation(distance);
		}
	}
	void GrandPrix::sortMembers()
	{
		for (int i = 0; i < numberOfMembers; i++)
		{
			for (int j = 0; j < numberOfMembers - i - 1; j++)
			{
				if (arrOfMembers[j]->getTime() > arrOfMembers[j + 1]->getTime())
				{
					Transport* temp = arrOfMembers[j];
					arrOfMembers[j] = arrOfMembers[j + 1];
					arrOfMembers[j + 1] = temp;
				}
			}
		}
	}
}