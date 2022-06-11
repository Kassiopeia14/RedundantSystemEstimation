#include "RepairUnit.h"
#include <iostream>

modSimpleSystemFastEstimation::RepairUnit::RepairUnit(const double lambda):
	lambda_(lambda),
	generator(lambda),
	repairTime_(DBL_MAX),
	isWorking(false)
{
}

modSimpleSystemFastEstimation::RepairUnit::~RepairUnit()
{
}

double modSimpleSystemFastEstimation::RepairUnit::run()
{
	return repairTime_;
}

void modSimpleSystemFastEstimation::RepairUnit::reset()
{
	repairTime_ = DBL_MAX;
	isWorking = false;
}

void modSimpleSystemFastEstimation::RepairUnit::reset(const double startTime)
{
	const double tau = generator.generate();
	repairTime_ = startTime + tau;
	isWorking = true;
}

bool modSimpleSystemFastEstimation::RepairUnit::working()
{
	return isWorking;
}
