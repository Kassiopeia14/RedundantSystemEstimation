#pragma once

#include <vector>

#include "MainElement.h"

class MainElementSet
{
private:

	std::vector<int> mainElementCounts;
	std::vector<double> mainElementLambdas;
	std::vector<MainElement> mainElements;
	
	static std::vector<double> makeMainElementLambdas(
		std::vector<int> _mainElementCounts,
		std::vector<double> _mainElementLambdas);

public:

	MainElementSet(
		std::vector<int> _mainElementCounts,
		std::vector<double> _mainElementLambdas);
	~MainElementSet();

	double getDeltaProbability(const double delta);

	void reset(
		const double startTime,
		const double testTime);

	void reset(
		int index,
		const double startTime,
		const double testTime);

	int findClosestElement();

	double getTime(int index);
	int getType(int index);
};