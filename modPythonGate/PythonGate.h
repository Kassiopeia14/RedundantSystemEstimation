#pragma once

#include <vector>

#include "../modTheory/SimpleTheory.h"
#include "../modSimpleSystemFastEstimation/SimpleRedundantSystem.h"
#include "../modSimpleSystemSimpleEstimation/SimpleRedundantSystem.h"

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

struct DataPoints
{
	double theoryResult;
	const size_t valueCount;
	double* simpleValues, *fastValues;

	DataPoints(
		double _theoryResult,
		std::vector<double> _simpleValues,
		std::vector<double> _fastValues);
};

extern "C" MATHLIBRARY_API DataPoints * getData(double lambda, double mu, double time);