#pragma once

#include <queue>

#include "MainElement.h"
#include "SpareElementSet.h"
#include "TypeCount.h"
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
		std::array<int, TYPE_COUNT> mainElementCounts,
		std::array<double, TYPE_COUNT> mainElementLambdas,
		std::array<int, TYPE_COUNT> _spareCounts,
		const int repairUnitCount,
		std::array<double, TYPE_COUNT> repairUnitLambdas,
		const double testTime);
	~ComplexRedundantSystem();

	void printDebug(std::string title);

	double doTest();
};