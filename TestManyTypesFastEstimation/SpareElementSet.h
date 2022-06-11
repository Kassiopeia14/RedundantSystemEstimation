#pragma once

#include <vector>

class SpareElementSet
{
private:

	std::vector<int> maxCounts, counts;

public:

	SpareElementSet(std::vector<int> _counts);
	~SpareElementSet();

	void reset();

	bool take(int type);
	void placeBack(int type);

	void print();
};