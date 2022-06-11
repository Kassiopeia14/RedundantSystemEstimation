#include "SimpleRedundantSystem.h"
#include <iostream>

modSimpleSystemSimpleEstimation::SimpleRedundantSystem::SimpleRedundantSystem(
	const double workElementLambda,
	const double repairUnitLambda,
	const double testTime) :
	mainElement(workElementLambda),
	spareElement(),
	repairUnit(repairUnitLambda),
	testTime_(testTime)
{
}

modSimpleSystemSimpleEstimation::SimpleRedundantSystem::~SimpleRedundantSystem()
{
}

bool modSimpleSystemSimpleEstimation::SimpleRedundantSystem::doTest()
{
	double workTime = 0;

	bool crash = false;

	mainElement.reset(workTime);
	spareElement.reset();
	repairUnit.reset();

	while ((workTime < testTime_) && !crash)
	{
		//std::cout << "****************************" << std::endl;
		double mainElementCrushTime = mainElement.run();
		double repairUnitRepairTime = repairUnit.run();
				
		if (mainElementCrushTime < testTime_)
		{
			if (mainElementCrushTime < repairUnitRepairTime)
			{
				//std::cout << "MAIN CRASH, T: " << mainElementCrushTime << std::endl;
				
				if (!spareElement.take())
				{
					//std::cout << "=== S Y S T E M  C R U S H ===" << std::endl << std::endl;
					crash = true;
				}
				else
				{
					workTime = mainElementCrushTime;
					mainElement.reset(workTime);

					if (!repairUnit.working())
					{
						repairUnit.reset(workTime);
					}
					else
					{
						throw;
					}
				}
			}
			else
			{
				//std::cout << "REPAIR, T: " << repairUnitRepairTime << std::endl;

				workTime = repairUnitRepairTime;
				repairUnit.reset();

				spareElement.placeBack();
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


