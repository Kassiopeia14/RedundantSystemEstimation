#include <iostream>
#include "ComplexRedundantSystem.h"

int main()
{
	std::cout << "BEGIN" << std::endl;

	double fres = 0;

	int N = 10;

	for (int k = 0; k < N; k++)
	{
		ComplexRedundantSystem system(
			{ 100 }, // main element counts
			{ 1.0 }, // main element lambdas
			{ 1 }, // spare element counts
			1, // repair unit count
			{ 5.0 }, // repair unit lambdas 
			1.0); // test time

		double freq = 0;
		int n = 10000;

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