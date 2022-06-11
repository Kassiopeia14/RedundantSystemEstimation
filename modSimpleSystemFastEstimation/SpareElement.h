#pragma once

namespace modSimpleSystemFastEstimation
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