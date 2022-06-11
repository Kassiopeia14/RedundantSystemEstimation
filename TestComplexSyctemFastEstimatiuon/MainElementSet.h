#pragma once

#include <array>
#include <vector>

#include "TypeCount.h"
#include "MainElement.h"

class MainElementSet
{
private:

	std::vector<double> mainElementLambdas0, mainElementLambdas1, mainElementLambdas2;
	std::vector<MainElement> mainElements0, mainElements1, mainElements2;
	std::vector<MainElement*> mainElements;
	
public:

	MainElementSet(
		std::array<int, TYPE_COUNT> mainElementCounts,
		std::array<double, TYPE_COUNT> mainElementLambdas);
	~MainElementSet();

	void reset(
		const double startTime,
		const double testTime);

	void reset(
		int index,
		const double startTime,
		const double testTime);

	int findClosestElement();

	double getTime(int index);
	double getDeltaProbability(int index);
	int getType(int index);
};