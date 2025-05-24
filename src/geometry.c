#include "geometry.h"

#define _GNU_SOURCE  /* to define Math constants */
#include <math.h>

double circle_area(double radius)
{
	return M_PI * radius * radius;
}

double circle_circumference(double radius)
{
	return 2 * M_PI * radius;
}


double compute_pi(void)
{
	double sum = 0.0;
	double sign = 1.0;
	int i;

	for (i = 0; i < TAYLOR_TERMS; ++i) {
		sum += sign / (2 * i + 1);
		sign *= -1.0;
	}

	return sum * 4.0; // Multiply by 4 to get the value of Pi
}
