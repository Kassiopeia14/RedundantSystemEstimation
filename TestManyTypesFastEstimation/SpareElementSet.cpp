#include "SpareElementSet.h"
#include <iostream>

SpareElementSet::SpareElementSet(std::vector<int> _counts) :
	maxCounts(_counts),
	counts(maxCounts)
{
}

SpareElementSet::~SpareElementSet()
{
}

void SpareElementSet::reset()
{
	for (int type = 0; type < maxCounts.size(); type++)
	{
		counts[type] = maxCounts[type];
	}	
}

bool SpareElementSet::take(int type)
{
	if (counts[type] < 1) return false;
	counts[type]--;
	return true;
}

void SpareElementSet::placeBack(int type)
{
	counts[type]++;
	if (counts[type] > maxCounts[type]) {		
		throw;
	}
}

void SpareElementSet::print()
{
	for (auto count = counts.begin(); count < counts.end(); count++)
	{
		std::cout << *count << " ";
	}
}