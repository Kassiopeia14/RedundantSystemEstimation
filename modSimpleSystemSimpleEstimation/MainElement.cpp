#include "MainElement.h"
#include <iostream>

modSimpleSystemSimpleEstimation::MainElement::MainElement(const double lambda) :
	generator(lambda),
	crushTime_(0)
{
}

modSimpleSystemSimpleEstimation::MainElement::~MainElement()
{
}

double modSimpleSystemSimpleEstimation::MainElement::run()
{
	return crushTime_;
}

void modSimpleSystemSimpleEstimation::MainElement::reset(const double startTime)
{
	const double tau = generator.generate();	
	crushTime_ = startTime + tau;
	//std::cout << "A1: 1, " << tau << ", start: " << startTime << ", finish: " << crushTime_ << std::endl;
}