#include "MainElement.h"
#include <iostream>

MainElement::MainElement(const double lambda) :
	generator(lambda),
	crushTime_(0)
{
}

MainElement::~MainElement()
{
}

void MainElement::reset(const double startTime)
{
	const double tau = generator.generate();
	crushTime_ = startTime + tau;
}

double MainElement::getTime()
{
	return crushTime_;
}
