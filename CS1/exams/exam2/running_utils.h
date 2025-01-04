/**
 * CSCE 155E - Fall 2024
 *
 * Exam 2
 * Prisha Sabherwal
 * 2024/10/25
 * A collection of function prototypes
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * conversion of 1 km per hour.
 */
#define KMS_PER_HOURS_TO_MILES_PER_HOUR 0.62137119
#define KMS_PER_HOURS_TO_FEET_PER_SECOND 0.91134442
#define KMS_PER_HOURS_TO_METERS_PER_SECOND 0.27777778
#define FEET_IN_A_METER 3.28084

/**
 * converts a given kph to the three units below.
 */
int convert(double kmsPerHours, double *milesPerHour, double *feetPerSecond, double *metersPerSecond);

/**
 * computes the total elevation gain given the elevationData points,
 * numPoints (number of elevation data points) and place the result
 * in the pass-by-reference variable gain.
 */
int elevationGain(double *elevationData, int numPoints, double *gain);

/**
 * a 2-D array elevations of dimensions n x m and creates and
 * returns a new 2-D array containing the converted values
 */
double **convertMap(double **elevationMap, int n, int m);
