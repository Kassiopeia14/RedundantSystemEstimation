#include <iostream>
#include "../modDistributions/ExponentialGeneratorSimple.h"
#include "../modDistributions/ExponentialGeneratorStd.h"


int main()
{
	std::cout << "BEGIN" << std::endl;

	const double lambda = 15;

	ExponentialGeneratorStd generator(lambda);

	double sum = 0;

	const int count = 100000;

	for (int i = 0; i < count; i++)
	{
		const double randomValue = generator.generate();
		//std::cout << randomValue << std::endl;

		sum += randomValue;
	}

	std::cout << "mean * lambda = " << lambda * sum / count << std::endl;

	return 0;
}