#include "geometry.h"

#include <math.h>


double compute_pi(int terms)
{
	double sum = 0.0;
	double sign = 1.0;
	int i;

	for (i = 0; i < terms; ++i) {
		sum += sign / (2 * i + 1);
		sign *= -1.0;
	}

	return sum * 4.0;
}
