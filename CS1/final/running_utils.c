/**
 * Author: Prish Sabherwal
 * 2024/12/16
 * This is a collection of function definitions
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#include "running_utils.h"

void initRunDataPoint(RunDataPoint *point, double latitude, double longitude, double elevation, const char *datetime) {
  point->latitude = latitude;
  point->longitude = longitude;
  point->elevation = elevation;
  strcpy(point->datetime, datetime);
}

void printRunDataPoint(const RunDataPoint *point) {
    printf("%s  %f, %f (%.2f)\n", point->datetime, point->latitude, point->longitude, point->elevation );
}

RunDataPoint *loadRunDataPoints(const char *fileName, int *numPoints) {

  FILE *in = fopen(fileName, "r");
  char buffer[100];
  char *s = fgets(buffer, 100, in);
  int numberOfPoints = 0;
  while(s != NULL) {
    s = fgets(buffer, 100, in);
    numberOfPoints++;
  }
  numberOfPoints--;
  *numPoints = numberOfPoints;

  RunDataPoint *points = (RunDataPoint *) malloc( sizeof(RunDataPoint) * numberOfPoints );

  rewind(in);
  s = fgets(buffer, 100, in);
  for(int i=0; i<numberOfPoints; i++) {
    s = fgets(buffer, 100, in);
    rtrim(buffer);
    if( strlen(buffer) > 0) {
        char *lat = strtok(buffer, ",");
        char *lon = strtok(NULL, ",");
        char *elev = strtok(NULL, ",");
        char *datetime = strtok(NULL, ",");
        double latitude = atof(lat);
        double longitude = atof(lon);
        double elevation = atof(elev);
        initRunDataPoint(&points[i], latitude, longitude, elevation, datetime);
    }
  }

  fclose(in);
  return points;
}

int timeDiff(const char *a, const char *b) {

    int a_year, a_month, a_day;
    int b_year, b_month, b_day;
    int a_hr, a_min, a_sec;
    int b_hr, b_min, b_sec;
    sscanf(a, "%d-%d-%dT%d:%d:%d", &a_year, &a_month, &a_day, &a_hr, &a_min, &a_sec);
    sscanf(b, "%d-%d-%dT%d:%d:%d", &b_year, &b_month, &b_day, &b_hr, &b_min, &b_sec);

    int diff = (b_hr-a_hr) * 3600 + (b_min-a_min) * 60 + (b_sec-a_sec);

    return diff;
}

char *formatTime(int seconds) {

    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int minutes = seconds / 60;
    seconds -= minutes * 60;
    char *result = (char *) malloc( sizeof(char) * 100 );
    sprintf(result, "%02d:%02d:%02d", hours, minutes, seconds);
    return result;
}

void rtrim(char *str) {
  int n = strlen(str);
  while (n >= 0 && isspace(str[n - 1])) {
    str[n - 1] = '\0';
    n--;
  }
  return;
}

int compareElevationAscending(const void *a, const void *b) {
    const RunDataPoint *pointA = (const RunDataPoint *)a;
    const RunDataPoint *pointB = (const RunDataPoint *)b;

    if (pointA->elevation > pointB->elevation) {
        return -1;
    } else if (pointA->elevation < pointB->elevation) {
        return 1;
    } else {
        return 0;
    }
}

int compareTimeAscending(const void *a, const void *b) {
    const RunDataPoint *timeA = (const RunDataPoint *)a;
    const RunDataPoint *timeB = (const RunDataPoint *)b;

    return strcmp(timeA->datetime, timeB->datetime);
}

double elevationGain (RunDataPoint *data, int numDataPoints) {
  double total = 0.0;
  for (int i = 1; i < numDataPoints; i++) {
    double difference = data[i].elevation - data[i - 1].elevation;
    if (difference > 0) {
      total += difference;
    }
  }
  return total;
}

double getAirDistance(const RunDataPoint* pointA, const RunDataPoint* pointB) {
    double radianLatitudeA = ((pointA->latitude / 180) * M_PI);
    double radianLatitudeB = ((pointB->latitude / 180) * M_PI);
    double radianLongitudeA = ((pointA->longitude / 180) * M_PI);
    double radianLongitudeB = ((pointB->longitude / 180) * M_PI);

    double diff_in_longitudes = (radianLongitudeB - radianLongitudeA);

    double distance = acos((sin(radianLatitudeA) * sin(radianLatitudeB)) + (cos(radianLatitudeA) * cos(radianLatitudeB) * cos(diff_in_longitudes))) * RADIUS_OF_EARTH;

    return distance;
}

double totalDistance(RunDataPoint *data, int numDataPoints) {
  double total = 0.0;
  for (int i = 1; i < numDataPoints; i++) {
    double difference = getAirDistance(&data[i - 1], &data[i]);
    if (difference > 0) {
      total += difference;
    }
  }
  return total;
}

void TimeReport(RunDataPoint *data, int numDataPoints) {
  int movingTime = 0;
  int waitTime = 0;

  for (int i = 1; i < numDataPoints; i++) {
    int difference = timeDiff(data[i - 1].datetime, data[i].datetime);
    if (difference < 10) {
        movingTime += difference;
    } else {
        waitTime += difference;
    }
  }
  int totalTime = movingTime + waitTime;

  char *formatMovingTime = formatTime(movingTime);
  char *formatWaitTime = formatTime(waitTime);
  char *formatTotalTime = formatTime(totalTime);

  printf("Moving time:    %s (%d)\n", formatMovingTime, movingTime);
  printf("Wait time:      %s (%d)\n", formatWaitTime, waitTime);
  printf("Total time:     %s (%d)\n", formatTotalTime, totalTime);

  free(formatMovingTime);
  free(formatWaitTime);
  free(formatTotalTime);
}
