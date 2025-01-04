/**
 * Prisha Sabherwal
 * 2024/11/14
 * This is a collection of function definitions involving
 * and airport structure.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "airport.h"

char *deepCopy(const char *array) {
  char *copy = malloc(sizeof(char) * (strlen(array)+1));
  strcpy(copy, array);
  return copy;
}

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {
  Airport *create = (Airport*) malloc(sizeof(Airport) * 1);
  initAirport(create, gpsId, type, name, latitude, longitude, elevationFeet, city, countryAbbrv);
  return create;
}

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {
  if(airport==NULL || gpsId==NULL || type==NULL || name==NULL || city==NULL || countryAbbrv==NULL) {
    return;
  }
  airport->gpsId = deepCopy(gpsId);
  airport->type = deepCopy(type);
  airport->name = deepCopy(name);
  airport->latitude = (latitude);
  airport->longitude = (longitude);
  airport->elevationFeet = (elevationFeet);
  airport->city = deepCopy(city);
  airport->countryAbbrv = deepCopy(countryAbbrv);
  return;
}

char* airportToString(const Airport* a) {
  if (a == NULL) {
    return NULL;
  }

  int n = strlen(a->gpsId) + strlen(a->type) + strlen(a->name) + 10 + 10 + 5 + strlen(a->city) + strlen(a->countryAbbrv) + 20;
  char *str = (char *)malloc(sizeof(char) * n);
  sprintf(str, "%s %s %s %.2f %.2f %d %s %s\n", a->gpsId, a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city, a->countryAbbrv);
  return str;
}

double getAirDistance(const Airport* origin, const Airport* destination){

  double radianLatitudeOrigin = ((origin->latitude/180)*M_PI);
  double radianLatitudeDestination = ((destination->latitude/180)*M_PI);
  double radianLongitudeOrigin = ((origin->longitude/180)*M_PI);
  double radianLongitudeDestination = ((destination->longitude/180)*M_PI);

  double diff_in_longitudes = (radianLongitudeDestination - radianLongitudeOrigin);

  double distance = acos((sin(radianLatitudeOrigin)*sin(radianLatitudeDestination))+(cos(radianLatitudeOrigin)*cos(radianLatitudeDestination)*cos(diff_in_longitudes)))*RADIUS_OF_EARTH;

  return distance;
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs){
  if(stops == NULL) {
    return 1;
  }
  double totalTime = 0;
  int i=0;
  for(i=0; i<(size-1); i++){
    double eachLeg = getAirDistance(&stops[i], &stops[i+1]);
    double eachLegTravelTime = eachLeg/aveKmsPerHour;
    totalTime += eachLegTravelTime;
    if(i<(size-2)){
      totalTime += aveLayoverTimeHrs;
    }
  }
  return totalTime;
}

void printAirport(const Airport * airport) {
  printf("%s, %s, %s, %lf, %lf, %d, %s, %s\n", airport->gpsId, airport->type, airport->name, airport->latitude, airport->longitude, airport->elevationFeet, airport->city, airport->countryAbbrv);
  return;
}
