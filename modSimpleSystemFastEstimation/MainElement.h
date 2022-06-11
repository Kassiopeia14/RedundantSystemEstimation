#pragma once

#include "../modDistributions/CRDGenerator.h"

namespace modSimpleSystemFastEstimation
{
	class MainElement
	{
	private:

		CRDGenerator generator;

		double
			deltaProbability,
			crushTime_;

	public:

		MainElement(const double lambda);
		~MainElement();

		double run();
		void reset(
			const double startTime,
			const double testTime);
		double getDeltaProbability();
	};
};

