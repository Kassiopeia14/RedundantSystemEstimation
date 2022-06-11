#include "CRDGenerator.h"

CRDGenerator::CRDGenerator(const double lambda):
	lambda_(lambda),	
	rd(),
	generator(rd()),
	distribution(0,1)
{
}

CRDGenerator::~CRDGenerator()
{
}

double CRDGenerator::getDeltaProbability(const double delta)
{
	return (1 - exp(-lambda_ * delta));
}

double CRDGenerator::generate(const double deltaProbability)
{
	const double u = distribution(generator);
	
	return -log(1 - u * deltaProbability) / lambda_;
}