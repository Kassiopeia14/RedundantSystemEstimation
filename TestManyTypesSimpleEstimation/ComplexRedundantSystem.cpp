#include "ComplexRedundantSystem.h"
#include <iostream>
#include <string>

ComplexRedundantSystem::ComplexRedundantSystem(
	std::vector<int> mainElementCounts,
	std::vector<double> mainElementLambdas,
	std::vector<int> _spareCounts,
	const int repairUnitCount,
	std::vector<double> repairUnitLambdas,
	const double testTime) :
	mainElementSet(mainElementCounts, mainElementLambdas),
	spareElementSet(_spareCounts),
	repairUnitSet(repairUnitCount, repairUnitLambdas),
	repairQueue(),
	testTime_(testTime)
{
}

ComplexRedundantSystem::~ComplexRedundantSystem()
{
}

void ComplexRedundantSystem::printDebug(std::string title)
{
	std::cout << title << ": ";
		
	spareElementSet.print();
	
	std::cout << " ### repair type " << repairUnitSet.getType(0) << " ### ";

	std::queue<int> q(repairQueue);

	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

bool ComplexRedundantSystem::doTest()
{
	double workTime = 0;
	double p = 1;

	bool crash = false;
	
	mainElementSet.reset(workTime);
	spareElementSet.reset();
	repairUnitSet.reset();
	std::queue<int> empty;
	std::swap(repairQueue, empty);
	
	while ((workTime < testTime_) && !crash)
	{
		int closestMainElement = mainElementSet.findClosestElement();
		int closestRepairUnit = repairUnitSet.findClosestUnit();
		
		double mainElementCrushTime = mainElementSet.getTime(closestMainElement);
		double repairUnitRepairTime = repairUnitSet.getTime(closestRepairUnit);
		
		if (mainElementCrushTime < testTime_)
		{
			if (mainElementCrushTime < repairUnitRepairTime)
			{	
				int mainElementType = mainElementSet.getType(closestMainElement);
				
				//printDebug("before take " + std::to_string(mainElementType));
				if (!spareElementSet.take(mainElementType))
				{
					//std::cout << "=== S Y S T E M  C R U S H ===" << std::endl << std::endl;
					crash = true;
				}
				else
				{
					workTime = mainElementCrushTime;

					int repairUnitIndex = repairUnitSet.findFreeUnit();

					if (repairUnitIndex < 0)
					{
						//printDebug("before push " + std::to_string(mainElementType));
						repairQueue.push(mainElementType);
						//printDebug("after push  ");
						//std::cout << std::endl;
					}
					else
					{
						repairUnitSet.reset(mainElementType, workTime);
					}
										
					mainElementSet.reset(closestMainElement, workTime);
					
				}
			}
			else
			{
				workTime = repairUnitRepairTime;

				int repairedElementType = repairUnitSet.getType(closestRepairUnit);
				//printDebug("before placeBack ");
				spareElementSet.placeBack(repairedElementType);
				//printDebug("after placeBack " + std::to_string(repairedElementType));
				repairUnitSet.reset(closestRepairUnit);

				if (!repairQueue.empty())				
				{
					//printDebug("before pop ");
					int elementTypeToRepair = repairQueue.front();
					repairQueue.pop();
					//printDebug("after pop  " + std::to_string(elementTypeToRepair));
					//std::cout << std::endl;

					repairUnitSet.reset(elementTypeToRepair, workTime);
				}								
			}
		}
		else
		{
			workTime = mainElementCrushTime;
		}
		
	}

	//if(workTime > testTime_) std::cout << "=== S Y S T E M  OK ===" << std::endl << std::endl;
	
	return !crash;
}


