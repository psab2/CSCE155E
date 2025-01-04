/**
 * Prisha Sabherwal
 * 2024/11/14
 * This is the Tester file for testing the functions
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

int main(int argc, char **argv) {
    printf("Test createAirport function\n");
    Airport* airport1 = createAirport("OMA", "International", "Omaha Eppley Airfield", 41.3036, -95.8944, 1001, "Omaha", "US-NE");
    Airport* airport2 = createAirport("BOS", "International", "Logan International Airport", 42.3656, -71.0096, 20, "Boston", "US-MA");
    Airport* airport3 = createAirport("ORD", "International", "O'Hare International Airport", 41.9742, -87.9073, 668, "Chicago", "US-IL");
    printAirport(airport1);
    printAirport(airport2);
    printAirport(airport3);
    free(airport1);
    free(airport2);
    free(airport3);
    printf("----------------\n");

    printf("Test initAirport function\n");
    Airport airport4, airport5, airport6;
    initAirport(&airport4, "OMA", "International", "Omaha Eppley Airfield", 41.3036, -95.8944, 1001, "Omaha", "US-NE");
    initAirport(&airport5, "BOS", "International", "Logan International Airport", 42.3656, -71.0096, 20, "Boston", "US-MA");
    initAirport(&airport6, "ORD", "International", "O'Hare International Airport", 41.9742, -87.9073, 668, "Chicago", "US-IL");
    printAirport(&airport4);
    printAirport(&airport5);
    printAirport(&airport6);
    printf("----------------\n");

    printf("Test airportToString function\n");
    char* airportStr1 = airportToString(&airport4);
    char* airportStr2 = airportToString(&airport5);
    char* airportStr3 = airportToString(&airport6);
    printf("String for airport1 is: %s\n", airportStr1);
    printf("String for airport2 is: %s\n", airportStr2);
    printf("String for airport3 is: %s\n", airportStr3);
    printf("----------------\n");

    printf("Test getAirDistance function\n");
    double airDistance1 = getAirDistance(&airport4, &airport5);
    double airDistance2 = getAirDistance(&airport4, &airport6);
    double airDistance3 = getAirDistance(&airport5, &airport6);
    printf("The air distance btw airport 1 & 2 is: %lf\n", airDistance1);
    printf("The air distance btw airport 1 & 3 is: %lf\n", airDistance2);
    printf("The air distance btw airport 2 & 3 is: %lf\n", airDistance3);
    printf("----------------\n");

    printf("Test getEstimatedTravelTime function\n");
    Airport stops1[3] = {airport4, airport5, airport6};
    Airport stops2[3] = {airport4, airport5, airport6};
    Airport stops3[3] = {airport4, airport5, airport6};
    double totalTime1 = getEstimatedTravelTime(stops1, 3, 800.0, 2.0);
    double totalTime2 = getEstimatedTravelTime(stops2, 2, 1050.0, 5.0);
    double totalTime3 = getEstimatedTravelTime(stops3, 1, 345.0, 1.0);
    printf("The estimated travel time btw airport 1, 2, & 3 with 3 stops is: %lf\n", totalTime1);
    printf("The estimated travel time btw airport 1, 2, & 3 with 2 stops is: %lf\n", totalTime2);
    printf("The estimated travel time btw airport 1, 2, & 3 with 1 stops is: %lf\n", totalTime3);
    printf("----------------\n");

    return 0;
}

