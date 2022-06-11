#pragma once

#include "../modDistributions/ExponentialGeneratorStd.h"

class MainElement
{
private:

	ExponentialGeneratorStd generator;

	double crushTime_;

public:

	MainElement(const double lambda);
	~MainElement();
		
	void reset(const double startTime);
	double getTime();
};