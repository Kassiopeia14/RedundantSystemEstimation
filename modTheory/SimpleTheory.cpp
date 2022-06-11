#include "SimpleTheory.h"

double theory(double lambda, double mu, double t)
{
	double
		q = sqrt(mu * (mu + 4 * lambda)),
		p = lambda + mu / 2,
		res = exp(-p * t) * (
			cosh(t * q / 2) + 2 * p * sinh(t * q / 2) / q
			);

	return 1.0 - res;
}