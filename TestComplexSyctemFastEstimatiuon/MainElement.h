#pragma once

#include "../modDistributions/CRDGenerator.h"

class MainElement
{
private:

	CRDGenerator generator;

	double 
		deltaProbability, 
		crushTime_;

public:

	MainElement(const double lambda);
	~MainElement();
		
	void reset(
		const double startTime, 
		const double testTime);
	double getTime();
	double getDeltaProbability();
};