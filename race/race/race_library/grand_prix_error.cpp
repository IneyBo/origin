#include "grand_prix_error.h"

namespace race
{
	GrandPrixError::GrandPrixError(std::string str) : std::domain_error(str)
	{

	}
}