#pragma once

#include <iostream>

namespace race
{
	class GrandPrixError : public std::domain_error
	{
	public:
		GrandPrixError(std::string str);
	};
}