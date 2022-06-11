#pragma once

#include "MainElement.h"
#include "SpareElement.h"
#include "RepairUnit.h"

namespace modSimpleSystemSimpleEstimation
{
	class SimpleRedundantSystem
	{
	private:

		MainElement mainElement;
		SpareElement spareElement;
		RepairUnit repairUnit;

		const double testTime_;

	public:

		SimpleRedundantSystem(
			const double workElementLambda,
			const double repairUnitLambda,
			const double testTime);
		~SimpleRedundantSystem();

		bool doTest();
	};
};