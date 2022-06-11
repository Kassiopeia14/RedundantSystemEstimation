#include <iostream>
#include "../modSimpleSystemFastEstimation/SimpleRedundantSystem.h"

int main()
{
	std::cout << "BEGIN" << std::endl;

	double fres = 0;

	int N = 20;

	for (int k = 0; k < N; k++)
	{
		modSimpleSystemFastEstimation::SimpleRedundantSystem system(1, 5, 5);

		double freq = 0;
		int n = 100000;

		for (int i = 0; i < n; i++)
		{
			freq += system.doTest();
		}

		freq /= n;

		std::cout << freq << std::endl;

		fres += freq;
	}

	fres /= N;

	std::cout << "average: " << fres << std::endl;

	return 0;
}