#pragma once

#include <cstdlib>
#include <random>

class CRDGenerator
{
private:

	const double lambda_;

	std::random_device rd;
	std::mt19937 generator;
	std::uniform_real_distribution<double> distribution;

public:

	CRDGenerator(const double lambda);
	~CRDGenerator();
    
	double getDeltaProbability(const double delta);

	double generate(const double deltaProbability);
};