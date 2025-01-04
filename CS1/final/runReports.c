/**
 * CSCE 155E/H
 * Final Exam
 * Fall 2024
 *
 * Author: Prish Sabherwal
 * 2024/12/16
 * A program producing reports on elevation, distance and time.
 *
 */
#include <stdlib.h>
#include <stdio.h>

#include "running_utils.h"

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: %s inputFileData.csv\n", argv[0]);
        exit(1);
    }

    int numDataPoints;
    RunDataPoint *data = loadRunDataPoints(argv[1], &numDataPoints);

    printf("=====================\n");
    printf(" Elevation Report    \n");
    printf("=====================\n");
    qsort(data, numDataPoints, sizeof(RunDataPoint), compareElevationAscending);
    printf("Highest Elevation: %.2fm\n", data[0].elevation);
    printf("Lowest Elevation: %.2fm\n", data[numDataPoints - 1].elevation);
    printf("\n\n");

    printf("=====================\n");
    printf(" Elevation Gain Report\n");
    printf("=====================\n");
    qsort(data, numDataPoints, sizeof(RunDataPoint), compareTimeAscending);
    double total = elevationGain(data, numDataPoints);
    printf("Elevation Gain: +%.2fm\n", total);
    printf("\n\n");

    printf("=====================\n");
    printf(" Distance Report     \n");
    printf("=====================\n");
    qsort(data, numDataPoints, sizeof(RunDataPoint), compareTimeAscending);
    double distance = totalDistance(data, numDataPoints);
    printf("Total distance: %.2fkm\n", distance);
    printf("\n\n");

    printf("=====================\n");
    printf(" Time Report     \n");
    printf("=====================\n");
    TimeReport(data, numDataPoints);


    return 0;
}
