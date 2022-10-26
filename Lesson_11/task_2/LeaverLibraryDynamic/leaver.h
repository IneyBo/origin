#pragma once

#include<string>

#ifdef LEAVERLIBRARYDUNAMIC_EXPORTS
#define LEAVERLIBRARY_API __declspec(dllexport)
#else
#define LEAVERLIBRARY_API __declspec(dllimport)
#endif

namespace Communication
{
	class Leaver
	{
	public:
		LEAVERLIBRARY_API std::string leave(std::string inputWord);
	};
}