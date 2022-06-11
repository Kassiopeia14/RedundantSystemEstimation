#include "../modTheory/SimpleTheory.h"

int main()
{
	double
		lambda = 1.0,
		mu = 5.0,
		t = 5.0;
		
	std::cout << theory(lambda, mu, t) << std::endl;

	return 0;
}