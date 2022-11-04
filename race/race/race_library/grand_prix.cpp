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
		for (int i = 0; i < numberOfMembers; i++) // иду по массиву от начала до конца
		{
			for (int j = 0; j < numberOfMembers - i - 1; j++) // начинаю поиск меньшего элемента уже с отсортированной части
			{
				if (arrOfMembers[j]->getTime() > arrOfMembers[j + 1]->getTime())
				{
					Transport* temp = arrOfMembers[j];
					arrOfMembers[j] = arrOfMembers[j + 1];
					arrOfMembers[j + 1] = temp;
				}
			}
		}

		//for (int k = 1; k < numberOfMembers; ++k) // иду по массиву от начала до конца
		//{
		//	for (int i = numberOfMembers - 1; i >= k; --i) // начинаю поиск меньшего элемента уже с отсортированной части
		//	{
		//		if (arrOfMembers[i]->getTime() < arrOfMembers[i - 1]->getTime())
		//		{
		//			Transport* temp = arrOfMembers[i - 1];
		//			arrOfMembers[i] = arrOfMembers[i - 1];
		//			arrOfMembers[i - 1] = temp;
		//		}
		//	}
		//}

		//bool swaped = false;
		//do
		//{
		//	bool swaped = false;	
		//	for (int i = 1; i < numberOfMembers; ++i)
		//	{
 	//			if (static_cast<int>(arrOfMembers[i - 1]->getTime()) > static_cast<int>(arrOfMembers[i]->getTime()))
		//		{
		//			Transport* temp = arrOfMembers[i - 1];
		//			arrOfMembers[i - 1] = arrOfMembers[i];
		//			arrOfMembers[i] = temp;
		//			swaped = true;
		//		}
		//	}
		//} while (swaped);
	}
}