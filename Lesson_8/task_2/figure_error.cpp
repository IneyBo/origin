#include "figure_error.h"

FigureError::FigureError(std::string str) : std::domain_error (str)
{

}