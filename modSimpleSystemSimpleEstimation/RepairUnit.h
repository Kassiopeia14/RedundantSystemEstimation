#pragma once

#include "../modDistributions/ExponentialGeneratorStd.h"
#include "../modDistributions/ExponentialGeneratorSimple.h"

namespace modSimpleSystemSimpleEstimation
{
	class RepairUnit
	{
	private:

		const double lambda_;

		ExponentialGeneratorStd generator;
		//ExponentialGeneratorSimple generator;

		bool isWorking;
		double repairTime_;

	public:
		RepairUnit(const double lambda);
		~RepairUnit();

		double run();
		void reset();
		void reset(const double startTime);
		bool working();
	};
};
