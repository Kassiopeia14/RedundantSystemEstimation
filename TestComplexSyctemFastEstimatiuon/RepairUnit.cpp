#include "RepairUnit.h"
#include <iostream>

RepairUnit::RepairUnit():	
	repairTime_(DBL_MAX),
	isWorking(false),
	type_(-1)
{
}

RepairUnit::~RepairUnit()
{
}

double RepairUnit::getTime()
{
	return repairTime_;
}

int RepairUnit::getType()
{
	return type_;
}

void RepairUnit::reset()
{
	type_ = -1;
	repairTime_ = DBL_MAX;
	isWorking = false;
}

void RepairUnit::reset(const int type, const double repairTime)
{
	type_ = type;
	repairTime_ = repairTime;
	isWorking = true;
}

bool RepairUnit::working()
{
	return isWorking;
}
