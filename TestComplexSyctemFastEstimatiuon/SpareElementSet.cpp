#include "SpareElementSet.h"
#include <iostream>

SpareElementSet::SpareElementSet(std::array<int, TYPE_COUNT> _counts) :
	maxCounts(_counts),
	counts(maxCounts)
{
}

SpareElementSet::~SpareElementSet()
{
}

void SpareElementSet::reset()
{
	for (int type = 0; type < TYPE_COUNT; type++)
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
	std::cout << counts[0] << " " << counts[1] << " " << counts[2];
}