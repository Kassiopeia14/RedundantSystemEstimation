#include "RepairUnit.h"
#include <iostream>

modSimpleSystemSimpleEstimation::RepairUnit::RepairUnit(const double lambda):
	lambda_(lambda),
	generator(lambda),
	repairTime_(DBL_MAX),
	isWorking(false)
{
}

modSimpleSystemSimpleEstimation::RepairUnit::~RepairUnit()
{
}

double modSimpleSystemSimpleEstimation::RepairUnit::run()
{
	return repairTime_;
}

void modSimpleSystemSimpleEstimation::RepairUnit::reset()
{
	repairTime_ = DBL_MAX;
	isWorking = false;
}

void modSimpleSystemSimpleEstimation::RepairUnit::reset(const double startTime)
{
	const double tau = generator.generate();
	repairTime_ = startTime + tau;
	//std::cout << "A4: 1, " << tau << ", start: " << startTime << ", finish: " << repairTime_ << std::endl;
	isWorking = true;
}

bool modSimpleSystemSimpleEstimation::RepairUnit::working()
{
	return isWorking;
}
