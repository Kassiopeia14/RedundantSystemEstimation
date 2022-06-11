#include "MainElement.h"
#include <iostream>

modSimpleSystemFastEstimation::MainElement::MainElement(const double lambda) :
	generator(lambda),
	crushTime_(0)
{
}

modSimpleSystemFastEstimation::MainElement::~MainElement()
{
}

double modSimpleSystemFastEstimation::MainElement::run()
{
	return crushTime_;
}

void modSimpleSystemFastEstimation::MainElement::reset(
	const double startTime,
	const double testTime)
{
	const double delta = testTime - startTime;
	deltaProbability = generator.getDeltaProbability(delta);

	const double tau = generator.generate(deltaProbability);
	crushTime_ = startTime + tau;
	//std::cout << "A1: p: " << deltaProbability << ", " << tau << ", start: " << startTime << ", finish: " << crushTime_ << std::endl;
}

double modSimpleSystemFastEstimation::MainElement::getDeltaProbability()
{
	return deltaProbability;
}