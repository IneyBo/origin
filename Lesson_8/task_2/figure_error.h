#pragma once

#include <iostream>

class FigureError : public std::domain_error
{
public:
	FigureError(std::string str);
};