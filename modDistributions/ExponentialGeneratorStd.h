#pragma once
#include <cstdlib>
#include <random>

class ExponentialGeneratorStd
{
private:

	const double lambda_;
	
	std::random_device rd;
	std::mt19937 generator;
	std::exponential_distribution<double> distribution;
	
public:
	
	ExponentialGeneratorStd(const double lambda);
	~ExponentialGeneratorStd();

	double generate();
};