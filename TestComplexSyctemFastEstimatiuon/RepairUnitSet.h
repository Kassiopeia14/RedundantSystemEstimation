#pragma once

#include <array>
#include <vector>

#include "TypeCount.h"
#include "../modDistributions/ExponentialGeneratorStd.h"
#include "RepairUnit.h"

class RepairUnitSet
{
private:

	ExponentialGeneratorStd generator0, generator1, generator2;

	std::array<ExponentialGeneratorStd*, TYPE_COUNT> generators;

	std::vector<RepairUnit> repairUnits;

public:
	RepairUnitSet(
		int count, 
		std::array<double, TYPE_COUNT> repairUnitLambdas);
	~RepairUnitSet();

	int findFreeUnit();
	int findClosestUnit();
	double getTime(int unitIndex);
	int getType(int unitIndex);
	void reset();
	void reset(int index);
	bool reset(const int type, const double startTime);
};

