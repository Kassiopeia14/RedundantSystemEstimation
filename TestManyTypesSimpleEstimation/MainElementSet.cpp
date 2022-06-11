#include "MainElementSet.h"

std::vector<double> MainElementSet::makeMainElementLambdas(
	std::vector<int> _mainElementCounts,
	std::vector<double> _mainElementLambdas)
{
	size_t arraySize = 0;
	auto countItem = _mainElementCounts.begin();
	for (; countItem != _mainElementCounts.end(); countItem++)
	{
		arraySize += *countItem;
	}

	std::vector<double> result(arraySize);

	auto resultItem = result.begin();
	countItem = _mainElementCounts.begin();
	auto lambdaItem = _mainElementLambdas.begin();
	for (; countItem != _mainElementCounts.end(), lambdaItem != _mainElementLambdas.end(); countItem++, lambdaItem++)
	{
		for (int i = 0; i < *countItem; i++, resultItem++)
		{
			*resultItem = *lambdaItem;
		}
	}

	return result;
}

MainElementSet::MainElementSet(
	std::vector<int> _mainElementCounts,
	std::vector<double> _mainElementLambdas):
	mainElementCounts(_mainElementCounts),
	mainElementLambdas(makeMainElementLambdas(mainElementCounts, _mainElementLambdas)),
	mainElements(mainElementLambdas.begin(), mainElementLambdas.end())
{	
}

MainElementSet::~MainElementSet()
{
}

void MainElementSet::reset(const double startTime)
{
	for (auto mainElement = mainElements.begin(); mainElement < mainElements.end(); mainElement++)
	{
		mainElement->reset(startTime);
	}		
}

void MainElementSet::reset(
	int index,
	const double startTime)
{	
	mainElements[index].reset(startTime);
}

int MainElementSet::findClosestElement()
{	
	int resultIndex = -1, i = 0;
	double closestCrushTime = DBL_MAX;
	for (auto unit = mainElements.begin(); unit != mainElements.end(); unit++, i++)
	{		
		const double crushTime = unit->getTime();
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
	return mainElements[index].getTime();
}

int MainElementSet::getType(int index)
{
	int i = 0;
	auto countItem = mainElementCounts.begin();
	int countSumm = *countItem;

	while (!(index < countSumm))
	{
		countItem++;
		countSumm += *countItem;		
		i++;
	}

	return i;
}