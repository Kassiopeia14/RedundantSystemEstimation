#define  MATHLIBRARY_EXPORTS
#include "PythonGate.h"

DataPoints::DataPoints(
	double _theoryResult,
	std::vector<double> _simpleValues,
	std::vector<double> _fastValues):
	theoryResult(_theoryResult),
	valueCount(_simpleValues.size()),
	simpleValues(new double[valueCount]),
	fastValues(new double[valueCount])
{
	auto value = simpleValues;

	for (auto item = _simpleValues.begin(); item != _simpleValues.end(); item++, value++)
	{
		*value = *item;
	}

	value = fastValues;

	for (auto item = _fastValues.begin(); item != _fastValues.end(); item++, value++)
	{
		*value = *item;
	}
}

DataPoints* getData(double lambda, double mu, double time)
{
	std::vector<double> 
		simpleResults(1000),
		fastResults(1000);

	double fres = 0;	
	int i = 1;
	
	for(auto point = simpleResults.begin(); point < simpleResults.end(); point++, i++)
	{
		modSimpleSystemSimpleEstimation::SimpleRedundantSystem system(lambda, mu, time);

		int success = 0;
		int n = 1000;

		for (int k = 0; k < n; k++)
		{
			if(system.doTest()) 
			{
				success++;
			}
		}

		double freq = (double)1.0 - ((double)success) / n;

		fres += freq;
		
		*point = fres / i;
	}

	fres = 0;
	i = 1;

	for (auto point = fastResults.begin(); point < fastResults.end(); point++, i++)
	{
		modSimpleSystemFastEstimation::SimpleRedundantSystem system(lambda, mu, time);

		double freq = 0;
		int n = 1000;

		for (int k = 0; k < n; k++)
		{
			freq += system.doTest();
		}

		freq /= n;

		fres += freq;

		*point = fres / i;
	}

	double theoryResult = theory(lambda, mu, time);

	return new DataPoints(theoryResult, simpleResults, fastResults);
}
