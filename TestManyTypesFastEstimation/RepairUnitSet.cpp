#include "RepairUnitSet.h"
#include <iostream>

RepairUnitSet::RepairUnitSet(
	int count, 
	std::vector<double> repairUnitLambdas):
	generators(repairUnitLambdas.begin(), repairUnitLambdas.end()),
	repairUnits(count)
{
}

RepairUnitSet::~RepairUnitSet()
{
}

int RepairUnitSet::findFreeUnit()
{
	int resultIndex = 0;
	auto unit = repairUnits.begin();
	while ((unit != repairUnits.end()) && (unit->working()))
	{
		unit++;
		resultIndex++;
	}

	if (unit == repairUnits.end())
	{
		resultIndex = -1;
	}

	return resultIndex;
}

int RepairUnitSet::findClosestUnit()
{
	int resultIndex = -1, i = 0;
	double resultRepairTime = DBL_MAX;
	for (auto unit = repairUnits.begin(); unit != repairUnits.end(); unit++, i++)
	{
		if (unit->working())
		{
			const double repairTime = unit->getTime();
			if (repairTime < resultRepairTime)
			{
				resultIndex = i;
				resultRepairTime = repairTime;
			}
		}
		
	}

	return resultIndex;
}

double RepairUnitSet::getTime(int unitIndex)
{
	if (unitIndex == -1)
	{
		return DBL_MAX;
	}

	return repairUnits[unitIndex].getTime();
}

int RepairUnitSet::getType(int unitIndex)
{
	if (unitIndex == -1)
	{
		return -1;
	}

	return repairUnits[unitIndex].getType();
}

void RepairUnitSet::reset()
{
	for (auto unit = repairUnits.begin(); unit != repairUnits.end(); unit++)
	{
		unit->reset();
	}
}

void RepairUnitSet::reset(int unitIndex)
{
	repairUnits[unitIndex].reset();
}

bool RepairUnitSet::reset(const int type, const double startTime)
{	
	int unitIndex = findFreeUnit();

	if (unitIndex < 0)
	{
		return false;
	}
	else
	{
		const double tau = generators[type].generate();
		const double repairTime = startTime + tau;

		repairUnits[unitIndex].reset(type, repairTime);

		return true;
	}
	
}
