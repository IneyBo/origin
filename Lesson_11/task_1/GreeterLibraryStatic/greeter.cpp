#include"greeter.h"

namespace Communication
{
	std::string Greeter::greet(std::string inputWord)
	{
		return "Здравствуйте, " + inputWord + "!";
	}
}