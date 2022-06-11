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


double MainElementSet::getDeltaProbability(const double delta)
{
	double lambda = 0;

	for (auto mainElement = mainElements.begin(); mainElement < mainElements.end(); mainElement++)
	{
		lambda += mainElement->getLambda();
	}

	return (1 - exp(-lambda * delta));
}

void MainElementSet::reset(
	const double startTime,
	const double testTime)
{
	const double delta = testTime - startTime;
	
	const double deltaProbability = getDeltaProbability(delta);
	for (auto mainElement = mainElements.begin(); mainElement < mainElements.end(); mainElement++)
	{
		//const double deltaProbability = mainElement->getDeltaProbability(delta);
		mainElement->reset(startTime, deltaProbability);
	}		
}

void MainElementSet::reset(
	int index,
	const double startTime,
	const double testTime)
{	
	const double delta = testTime - startTime;
	const double deltaProbability = getDeltaProbability(delta);
	//const double deltaProbability = mainElements[index].getDeltaProbability(delta);
	mainElements[index].reset(startTime, deltaProbability);
}

int MainElementSet::findClosestElement()
{	
	int resultIndex = -1, i = 0;
	double closestCrushTime = DBL_MAX;
	for (auto element = mainElements.begin(); element != mainElements.end(); element++, i++)
	{		
		const double crushTime = element->getTime();
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