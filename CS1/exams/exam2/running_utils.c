/**
 * CSCE 155E - Fall 2024
 *
 * Exam 2
 * Prisha Sabherwal
 * 2024/10/25
 * Implementation of the functions
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "running_utils.h"

/**
 * converts a given kph to the three units below.
 */
int convert(double kmsPerHours, double *milesPerHour, double *feetPerSecond, double *metersPerSecond) {
    if(kmsPerHours < 0 || milesPerHour == NULL || feetPerSecond == NULL || metersPerSecond == NULL) {
        return 1;
    }

    *milesPerHour = kmsPerHours * KMS_PER_HOURS_TO_MILES_PER_HOUR;
    *feetPerSecond = kmsPerHours * KMS_PER_HOURS_TO_FEET_PER_SECOND;
    *metersPerSecond = kmsPerHours * KMS_PER_HOURS_TO_METERS_PER_SECOND;

    return 0;
}

/**
 * computes the total elevation gain given the elevationData points,
 * numPoints (number of elevation data points) and place the result
 * in the pass-by-reference variable gain.
 */
int elevationGain(double *elevationData, int numPoints, double *gain) {
    if(elevationData == NULL || numPoints < 0 || gain == NULL) {
        return 1;
    }

    *gain = 0.0;
    for(int i=1; i<numPoints; i++) {
        double elevationGain = elevationData[i]-elevationData[i-1];
        if (elevationGain > 0.0) {
            *gain += elevationGain;
        }
    }

    return 0;
}

/**
 * a 2-D array elevations of dimensions n x m and creates and
 * returns a new 2-D array containing the converted values
 */
double **convertMap(double **elevationMap, int n, int m) {
    if(elevationMap == NULL || n < 0 || m < 0) {
        return NULL;
    }

    double **map = (double **) malloc(sizeof(double *) * n);
    for(int i=0; i<n; i++) {
        map[i] = (double *) malloc(sizeof(double) * m);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            map[i][j] = FEET_IN_A_METER * elevationMap[i][j];
        }
    }

    return map;
}
