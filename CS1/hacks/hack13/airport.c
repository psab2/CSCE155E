/**
 * Prisha Sabherwal
 * 2024/12/01
 * This is a collection of function definitions involving
 * and airport structure.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "airport.h"

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);

  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  printAirports(airports, n);

  printf("\nAirports By Type: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  printAirports(airports, n);

  printf("\nAirports By Name: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  printAirports(airports, n);

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  printAirports(airports, n);

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  printAirports(airports, n);

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  printAirports(airports, n);

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAirports(airports, n);

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirports(airports, n);

  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");
  if (n > 0) {
    Airport* closest = &airports[0];
    char* string = airportToString(closest);
    printf("%s\n", string);
    free(string);
  }

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");
  if (n > 0) {
    Airport* furthest = &airports[n - 1];
    char* string = airportToString(furthest);
    printf("%s\n", string);
    free(string);
  }

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");
  if (n > 0) {
    qsort(airports, n, sizeof(Airport), cmpByLongitude);
    Airport* median = &airports[n / 2];
    char* string = airportToString(median);
    printf("%s\n", string);
    free(string);
  }

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  int NewYorkAirport = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(airports[i].city, "New York") == 0 && strcmp(airports[i].countryAbbrv, "US") == 0) {
      char* string = airportToString(&airports[i]);
      printf("%s\n", string);
      free(string);
      NewYorkAirport++;
    }
  }
  if(NewYorkAirport<=0){
    printf("No New York airport found!\n");
  }

  printf("\nLarge airport: \n");
  printf("==============================\n");
  int numOfLargeAirport = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(airports[i].type, "large_airport") == 0) {
      char* string = airportToString(&airports[i]);
      printf("%s\n", string);
      free(string);
      numOfLargeAirport++;
    }
  }
  if(numOfLargeAirport<=0){
    printf("No large airport found!\n");
  }


  return;
}

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
  char temp[1000];
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}

void printAirports(Airport *airports, int n) {

  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }

  return;
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

int cmpByGPSId(const void* a, const void* b) {
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;

  return strcmp(airport1->gpsId, airport2->gpsId);
}

int cmpByType(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;

  return strcmp(airport1->type, airport2->type);
}

int cmpByName(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;

  return strcmp(airport1->name, airport2->name);
}

int cmpByNameDesc(const void* a, const void* b){
	 const Airport *airport1 = (const Airport *)a;
	 const Airport *airport2 = (const Airport *)b;
	 int r = strcmp(airport1->name, airport2->name);
	 if (r == 0){
		return 0;
	 }else{
		return -r;
	 }
}

int cmpByCountryCity(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;
  int r = strcmp(airport1->countryAbbrv, airport2->countryAbbrv);
  if (r == 0){
	return strcmp(airport1->city, airport2->city);
  }else{
   return r;
  }
}

int cmpByLatitude(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;

   if(airport1->latitude > airport2->latitude){
		 return -1;
	 }else if(airport1->latitude < airport2->latitude){
		 return 1;
	 }else{
		 return 0;
	 }
}

int cmpByLongitude(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;

   if(airport1->longitude < airport2->longitude){
		 return -1;
	 }else if(airport1->longitude > airport2->longitude){
		 return 1;
	 }else{
		 return 0;
	 }
}

double LincolnDistance(const Airport* airport){
  double radianLatitudeLincoln = ((LINCOLN_LATITUDE/180)*M_PI);
  double radianLatitudeAirport = ((airport->latitude/180)*M_PI);
  double radianLongitudeLincoln = ((LINCOLN_LONGITUDE/180)*M_PI);
  double radianLongitudeAirport = ((airport->longitude /180)*M_PI);

  double diff_in_longitudes = (radianLongitudeAirport - radianLongitudeLincoln);

  double distance = acos((sin(radianLatitudeLincoln)*sin(radianLatitudeAirport))+(cos(radianLatitudeLincoln)*cos(radianLatitudeAirport)*cos(diff_in_longitudes)))*RADIUS_OF_EARTH;

  return distance;
}

int cmpByLincolnDistance(const void* a, const void* b){
  const Airport *airport1 = (const Airport *)a;
  const Airport *airport2 = (const Airport *)b;
  double distance1 = LincolnDistance(airport1);
  double distance2 = LincolnDistance(airport2);

   if(distance1 < distance2){
		 return -1;
	 }else if(distance1 > distance2){
		 return 1;
	 }else{
		 return 0;
	 }
}


