/**
 * Prisha Sabherwal
 * 2024/12/01
 * This is the file that contains the reports
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"

int main(int argc, char **argv) {

    Airport *OMA = createAirport("OMA1",     "normal",          "Eppley Airfield",         41.30,   -95.89,  150, "Omaha",           "US");
    Airport *CHI0 = createAirport("CHI0",     "huge",            "O'Hare",                  41.97,   -87.91,  125, "Chicago",         "US");
    Airport *YYZA = createAirport("YYZA",     "medium",           "Pearson",                 43.60,   -79.60,  25,  "Toronto",         "CN");
    Airport *NYNY = createAirport("NYNY",     "intl",             "LaGuardia",               40.78,   -73.87,  50,  "New York",        "US");
    Airport *YACS = createAirport("YACS",     "small_airport",   "Acacia Downs",            -31.42,  141.90,  0,   "None",            "AU");
    Airport *TX0 = createAirport("9TX0",     "heliport",        "Houston Police ",         29.66,   -95.32,  40,  "Houston",         "US");
    Airport *EDDH = createAirport("EDDH",     "large_airport",   "Hamburg Airport",        53.63,   9.99,    53,  "Hamburg",          "DE");
    Airport *KS = createAirport("99KS",      "tiny",            "Elm Creek",              37.41,   -98.65,  1600, "Medicine Lodge",  "US");
    Airport *MA = createAirport("26MA",      "tiny_airport",    "Pepperell Airport",      42.70,   -71.55,  176,  "Pepperell",       "US");
    Airport *KIXA = createAirport("KIXA",    "one_strip",       "Halifax-Northampton", 36.33,   -77.64,  145,  "Roanoke Rapids",  "US");

    Airport airports[]={*OMA, *CHI0, *YYZA, *NYNY, *YACS, *TX0, *EDDH, *KS, *MA, *KIXA};

    generateReports(airports, 10);

    return 0;
}

