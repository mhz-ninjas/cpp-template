#define _GNU_SOURCE  /* to define Math constants */

#include <stdio.h>
#include <math.h>

#include "geometry.h"

int main(void)
{
	int passed_tests = 2;

	// Test the area of a circle
	double radius = 3.0;

	double area_circle = circle_area(radius);
	double expected_area_circle = M_PI * radius * radius;
	double tolerance = 0.00001;
	// Check if the calculated area is within the tolerance range
	// Using a range check to account for floating-point precision issues
	double error = fabs(area_circle - expected_area_circle);

	if (error < tolerance) {
		printf("Test passed: Area of circle is %.2f\n", area_circle);
		--passed_tests;
	} else {
		printf("Test failed: Expected %.2f, got %.2f\n", expected_area_circle, area_circle);
	}


	double computed_pi = compute_pi();
	if (fabs(computed_pi - M_PI) < tolerance) {
		printf("Test passed: Computed Pi is %.5f\n", computed_pi);
		--passed_tests;
	} else {
		printf("Test failed: Expected %.9f, got %.9f\n", M_PI, computed_pi);
	}

	return passed_tests;
}
