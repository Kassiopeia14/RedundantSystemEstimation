#pragma once

#include "../modDistributions/CRDGenerator.h"

class MainElement
{
private:

	double 
		lambda_,
		crushTime_;

	CRDGenerator generator;

public:

	MainElement(const double lambda);
	~MainElement();
		
	double getLambda();

	double getDeltaProbability(const double delta);

	void reset(
		const double startTime, 
		const double deltaProbability);
	double getTime();
};