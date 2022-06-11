#include <iostream>
#include "../modSimpleSystemSimpleEstimation/SimpleRedundantSystem.h"

int main()
{
	std::cout << "BEGIN" << std::endl;

	double fres = 0;

	int N = 20;

	for (int k = 0; k < N; k++)
	{
		modSimpleSystemSimpleEstimation::SimpleRedundantSystem system(1, 5, 5);

		int success = 0;
		int n = 1000000;

		for (int i = 0; i < n; i++)
		{
			if (system.doTest())
			{
				success++;
			}
		}

		const double freq = (double)1.0 - ((double)success) / n;

		std::cout << freq << std::endl;

		fres += freq;
	}

	fres /= N;

	std::cout << "average: " << fres << std::endl;

	return 0;
}