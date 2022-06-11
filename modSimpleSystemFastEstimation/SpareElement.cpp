#include "SpareElement.h"
#include <iostream>

modSimpleSystemFastEstimation::SpareElement::SpareElement() :
	count(1)
{
}

modSimpleSystemFastEstimation::SpareElement::~SpareElement()
{
}

void modSimpleSystemFastEstimation::SpareElement::reset()
{
	count = 1;
}

bool modSimpleSystemFastEstimation::SpareElement::take()
{
	if (count < 1) return false;
	count--;
	//std::cout << "A2: " << count << std::endl;
	return true;
}

void modSimpleSystemFastEstimation::SpareElement::placeBack()
{
	count++;
	//std::cout << "A2: " << count << std::endl;
	if (count > 1) throw;
}