#include "ExponentialGeneratorSimple.h"

double ExponentialGeneratorSimple::uniform() const
{
	return ((double)(1 + rand())) / (1 + RAND_MAX);
}

ExponentialGeneratorSimple::ExponentialGeneratorSimple(const double lambda):
	lambda_(lambda)
{	
}

ExponentialGeneratorSimple::~ExponentialGeneratorSimple()
{
}

double ExponentialGeneratorSimple::generate() const
{
	const double uniformRandom = uniform();
	return -log(uniformRandom) / lambda_;
}