#include "SpareElement.h"
#include <iostream>

modSimpleSystemSimpleEstimation::SpareElement::SpareElement() :
	count(1)
{
}

modSimpleSystemSimpleEstimation::SpareElement::~SpareElement()
{
}

void modSimpleSystemSimpleEstimation::SpareElement::reset()
{
	count = 1;
}

bool modSimpleSystemSimpleEstimation::SpareElement::take()
{
	if (count < 1) return false;
	count--;
	//std::cout << "A2: " << count << std::endl;
	return true;
}

void modSimpleSystemSimpleEstimation::SpareElement::placeBack()
{
	count++;
	//std::cout << "A2: " << count << std::endl;
	if (count > 1) throw;
}