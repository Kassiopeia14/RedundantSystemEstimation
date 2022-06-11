#include "MainElementSet.h"

MainElementSet::MainElementSet(
	std::array<int, TYPE_COUNT> mainElementCounts,
	std::array<double, TYPE_COUNT> mainElementLambdas):
	mainElementLambdas0(mainElementCounts[0], mainElementLambdas[0]),
	mainElementLambdas1(mainElementCounts[1], mainElementLambdas[1]),
	mainElementLambdas2(mainElementCounts[2], mainElementLambdas[2]),
	mainElements0(mainElementLambdas0.begin(), mainElementLambdas0.end()),
	mainElements1(mainElementLambdas1.begin(), mainElementLambdas1.end()),
	mainElements2(mainElementLambdas2.begin(), mainElementLambdas2.end()),
	mainElements(mainElements0.size() + mainElements1.size() + mainElements2.size(), 0)
{
	auto mainElement = mainElements.begin();
	for (auto mainElement0 = mainElements0.begin(); mainElement0 != mainElements0.end(); mainElement++, mainElement0++)
	{
		*mainElement = &*mainElement0;
	}
	for (auto mainElement1 = mainElements1.begin(); mainElement1 != mainElements1.end(); mainElement++, mainElement1++)
	{
		*mainElement = &*mainElement1;
	}
	for (auto mainElement2 = mainElements2.begin(); mainElement2 != mainElements2.end(); mainElement++, mainElement2++)
	{
		*mainElement = &*mainElement2;
	}
}

MainElementSet::~MainElementSet()
{
}

void MainElementSet::reset(
	const double startTime,
	const double testTime)
{
	for (auto mainElement = mainElements.begin(); mainElement < mainElements.end(); mainElement++)
	{
		(*mainElement)->reset(startTime, testTime);
	}		
}

void MainElementSet::reset(
	int index,
	const double startTime,
	const double testTime)
{	
	mainElements[index]->reset(startTime, testTime);
}

int MainElementSet::findClosestElement()
{	
	int resultIndex = -1, i = 0;
	double closestCrushTime = DBL_MAX;
	for (auto unit = mainElements.begin(); unit != mainElements.end(); unit++, i++)
	{		
		const double crushTime = (*unit)->getTime();
		if (crushTime < closestCrushTime)
		{
			resultIndex = i;
			closestCrushTime = crushTime;
		}
	}
	return resultIndex;
}

double MainElementSet::getTime(int index)
{
	return mainElements[index]->getTime();
}

double MainElementSet::getDeltaProbability(int index)
{
	return mainElements[index]->getDeltaProbability();
}

int MainElementSet::getType(int index)
{
	const int size0 = mainElements0.size();

	if (index < size0) return 0;
	
	const int size1 = size0 + mainElements1.size();

	if (index < size1) return 1;

	const int size2 = size1 + mainElements2.size();

	if (index < size2) return 2;
}