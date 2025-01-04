/**
 * Prisha Sabherwal
 * 2024/10/03
 * the test case file
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "utils.h"

/**
 * This function returns true if the two given
 * values a, b are within DELTA of each other.
 */

int main(int argc, char **argv) {

  int reportPass = 0;

  double degree, originLatitude, originLongitude, destinationLatitude, destinationLongitude, t, percentC;
  double result;
  double expectedResult;
  int numPassed = 0;
  int numFailed = 0;

//degreesToRadians test case

  degree = 20.0;
  expectedResult = 0.349066;
  printf("TESTING: degreesToRadians(%.6f): ", degree);
  result = degreesToRadians(degree);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: degreesToRadians returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  degree = 180.0;
  expectedResult = 3.141593;
  printf("TESTING: degreesToRadians(%.6f): ", degree);
  result = degreesToRadians(degree);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: degreesToRadians returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  degree = 60.0;
  expectedResult = 1.047198;
  printf("TESTING: degreesToRadians(%.6f): ", degree);
  result = degreesToRadians(degree);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: degreesToRadians returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

//getAirDistance test case

  originLatitude = 8.0, originLongitude = 9.0, destinationLatitude = 12.0, destinationLongitude = 11.0;
  expectedResult = 495.755451;
  printf("TESTING: getAirDistance(%.6f,%.6f,%.6f,%.6f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: getAirDistance returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  originLatitude = 45.0, originLongitude = 65.0, destinationLatitude = 50.0, destinationLongitude = 70.0;
  expectedResult = 670.621466;
  printf("TESTING: getAirDistance(%.6f,%.6f,%.6f,%.6f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: getAirDistance returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  originLatitude = 44.0, originLongitude = 79.0, destinationLatitude = 28.0, destinationLongitude = 88.0;
  expectedResult = 1951.726508;
  printf("TESTING: getAirDistance(%.6f,%.6f,%.6f,%.6f): ", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: getAirDistance returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

//lorentzTimeDilation test case

  t = 44.0, percentC = .96;
  expectedResult = 157.142857;
  printf("TESTING: lorentzTimeDilation(%.6f,%.6f): ", t, percentC);
  result = lorentzTimeDilation(t, percentC);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: lorentzTimeDilation returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  t = 24.0, percentC = .43;
  expectedResult = 26.583110;
  printf("TESTING: lorentzTimeDilation(%.6f,%.6f): ", t, percentC);
  result = lorentzTimeDilation(t, percentC);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: lorentzTimeDilation returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  t = 60.0, percentC = .59;
  expectedResult = 74.312310;
  printf("TESTING: lorentzTimeDilation(%.6f,%.6f): ", t, percentC);
  result = lorentzTimeDilation(t, percentC);
  if(fabs(result - expectedResult) > 0.01) {
    printf("FAILED: lorentzTimeDilation returned %.6f, expected %.6f\n", result, expectedResult);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("Number Test Cases Passed: %6d\n", numPassed);
  printf("Number Test Cases Failed: %6d\n", numFailed);
  printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

  if(reportPass) {
    return numPassed;
  } else {
    return numFailed;
  }

}
