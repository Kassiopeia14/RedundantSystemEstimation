#include "ExponentialGeneratorStd.h"

ExponentialGeneratorStd::ExponentialGeneratorStd(const double lambda) :
	lambda_(lambda),
	rd(),
	generator(rd()),
	distribution(lambda_)
{
}

ExponentialGeneratorStd::~ExponentialGeneratorStd()
{
}

double ExponentialGeneratorStd::generate()
{		
	return distribution(generator);
}