#pragma once

#include <queue>

#include "MainElement.h"
#include "SpareElementSet.h"
#include "MainElementSet.h"
#include "RepairUnitSet.h"

class ComplexRedundantSystem
{
private:

	MainElementSet mainElementSet;
	SpareElementSet spareElementSet;
	RepairUnitSet repairUnitSet;
	std::queue<int> repairQueue;

	const double testTime_;

public:

	ComplexRedundantSystem(
		std::vector<int> mainElementCounts,
		std::vector<double> mainElementLambdas,
		std::vector<int> _spareCounts,
		const int repairUnitCount,
		std::vector<double> repairUnitLambdas,
		const double testTime);
	~ComplexRedundantSystem();

	void printDebug(std::string title);

	bool doTest();
};