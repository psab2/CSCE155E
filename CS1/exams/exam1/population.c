/**
 * Author: Prisha
 * 2024/09/27
 * program that takes the initial population, geometric rate and arithmetic rate
 * and outputs a table of how the population will increase year to year along
 * with an average of the two models until the average population has doubled
 * from the initial population.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if(argc!=4) {
    printf("ERROR: enter the initial population, geometric rate, arithmetic rate\n");
    exit(1);
  }

  double initialPopulation = atof(argv[1]);
  double geometricRate = atof(argv[2]);
  double arithmeticRate = atof(argv[3]);

  if(initialPopulation<0) {
    printf("ERROR: provide 3 valid inputs\n");
    exit(1);
  }

  double average;
  double n = initialPopulation*2;
  double geometricPopulation = initialPopulation;
  double arithmeticPopulation = initialPopulation;
  int year=0;
  average = initialPopulation;
  printf("Initial Population: %.0f\n", initialPopulation);
  printf("Years        Geometric      Arithmetic   Average\n");
  while(average<n) {
    year++;
    geometricPopulation = round(geometricPopulation + (geometricPopulation * geometricRate));
    arithmeticPopulation = arithmeticPopulation + arithmeticRate;
    average = round((geometricPopulation+arithmeticPopulation)/2);
    printf("%5d        %5.0f       %8.0f      %9.0f\n", year, geometricPopulation, arithmeticPopulation, average);
  }
 return(0);
}
