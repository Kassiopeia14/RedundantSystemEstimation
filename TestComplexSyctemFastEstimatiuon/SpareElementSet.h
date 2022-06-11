#pragma once

#include <array>

#include "TypeCount.h"

class SpareElementSet
{
private:

	std::array<int, TYPE_COUNT> maxCounts, counts;

public:

	SpareElementSet(std::array<int, TYPE_COUNT> _counts);
	~SpareElementSet();

	void reset();

	bool take(int type);
	void placeBack(int type);

	void print();
};