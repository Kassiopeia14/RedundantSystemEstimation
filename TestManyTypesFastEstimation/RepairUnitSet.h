#pragma once

#include <vector>

#include "../modDistributions/ExponentialGeneratorStd.h"
#include "RepairUnit.h"

class RepairUnitSet
{
private:

	std::vector<ExponentialGeneratorStd> generators;

	std::vector<RepairUnit> repairUnits;

public:
	RepairUnitSet(
		int count, 
		std::vector<double> repairUnitLambdas);
	~RepairUnitSet();

	int findFreeUnit();
	int findClosestUnit();
	double getTime(int unitIndex);
	int getType(int unitIndex);
	void reset();
	void reset(int index);
	bool reset(const int type, const double startTime);
};

