#ifndef GEOMETRY_H
#define GEOMETRY_H

/**
 * @file geometry.h
 * @brief Header file for geometry-related functions.
 *
 * This file contains declarations for functions that compute the area and circumference
 * of a circle, as well as a function to compute the value of Pi.
 */


/**
 * @brief Computes the area of a circle given its radius.
 *
 * @param radius
 * @return double
 */
double circle_area(double radius);

/**
 * @brief Computes the circumference of a circle given its radius.
 *
 * @param radius
 * @return double
 */
 double circle_circumference(double radius);

/**
 * @brief Compute the value of Pi using a numerical method.
 *
 * @return double
 */
double compute_pi(void);

#define TAYLOR_TERMS 1000000 /**< Number of terms in the Taylor series for Pi */

#endif /* GEOMETRY_H */
