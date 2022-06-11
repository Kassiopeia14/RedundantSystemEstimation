#include "MainElement.h"
#include <iostream>

MainElement::MainElement(const double lambda) :
	lambda_(lambda),
	crushTime_(0),
	generator(lambda_)
{
}

MainElement::~MainElement()
{
}

double MainElement::getLambda()
{
	return lambda_;
}

double MainElement::getDeltaProbability(const double delta)
{
	return (1 - exp(-lambda_ * delta));
}

void MainElement::reset(
	const double startTime,
	double deltaProbability)
{
	const double tau = generator.generate(deltaProbability);
	crushTime_ = startTime + tau;	
}

double MainElement::getTime()
{
	return crushTime_;
}
