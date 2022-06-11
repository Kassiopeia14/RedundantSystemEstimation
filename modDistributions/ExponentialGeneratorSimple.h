#pragma once

#include <cstdlib>

class ExponentialGeneratorSimple
{
private:

	const double lambda_;
		
	double uniform() const;

public:

	ExponentialGeneratorSimple(const double lambda);
	~ExponentialGeneratorSimple();

	double generate() const;

};