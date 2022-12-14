#pragma once
#include "transport.h"

namespace race
{
	class GroundTransport : public Transport
	{
	protected:
		int timeBeforeRest;
		int raceDuration1, raceDuration2, raceDurationNext;
	public:
		GroundTransport();
	};
}