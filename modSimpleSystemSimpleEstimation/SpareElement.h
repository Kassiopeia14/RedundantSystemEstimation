#pragma once

namespace modSimpleSystemSimpleEstimation
{
	class SpareElement
	{
	private:

		int count;

	public:

		SpareElement();
		~SpareElement();

		void reset();

		bool take();
		void placeBack();
	};

};