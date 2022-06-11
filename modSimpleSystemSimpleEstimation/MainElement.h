#pragma once

#include "../modDistributions/ExponentialGeneratorStd.h"

namespace modSimpleSystemSimpleEstimation
{
	class MainElement
	{
	private:

		ExponentialGeneratorStd generator;

		double crushTime_;

	public:

		MainElement(const double lambda);
		~MainElement();

		double run();
		void reset(const double startTime);
	};
};

