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

void MainElement::reset(
	const double startTime,
	const double testTime)
{
	const double delta = testTime - startTime;
	deltaProbability = generator.getDeltaProbability(delta);

	const double tau = generator.generate(deltaProbability);
	crushTime_ = startTime + tau;	
}

double MainElement::getTime()
{
	return crushTime_;
}

double MainElement::getDeltaProbability()
{
	return deltaProbability;
}