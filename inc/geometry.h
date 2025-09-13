#ifndef GEOMETRY_H
#define GEOMETRY_H

/**
 * @file geometry.h
 * @brief Header file for geometry-related functions.
 *
 * Author: Muhammad Z
 * This file contains declarations for functions that compute the value of Pi.
 * using taylor series.
 */



/**
 * @brief Compute the value of Pi using the Taylor series.
 *
 * @param series_terms  Number of terms in the Taylor series to compute Pi.
 * @return double computed value of Pi.
 */
double compute_pi(int series_terms);

#define TAYLOR_TERMS 1000000 /**< Suggested number of terms in the Taylor series for Pi */

#endif /* GEOMETRY_H */
