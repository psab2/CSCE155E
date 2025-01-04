/**
 * CSCE 155E/H - Fall 2024
 *
 * Exam 2 tester - use this file, modify it, etc. to debug
 * your functions, but you will not be handing it in.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "running_utils.h"

int main(int argc, char **argv) {

  double kph = 10.9;
  double mph, fps, mps;
  int errorCode;

  errorCode = convert(kph, &mph, &fps, &mps);
  printf("%.3f kph is %.3f mph, %.3f fps, %.3f mps\n", kph, mph, fps, mps);

  double elevations[] = {350, 352.5, 351.2, 355.2, 354.0};
  double gain;
  errorCode = elevationGain(elevations, 5, &gain);
  printf("Total Elevation Gain: %f\n", gain);

  double **map = (double **) malloc(sizeof(double *) * 3);
  double a[] = { 9.50, 8.75, 7.25, 8.25, 8.25 };
  double b[] = { 8.50, 9.35, 6.45, 6.50, 7.25 };
  double c[] = { 7.50, 8.60, 4.50, 5.50, 5.75 };
  map[0] = a;
  map[1] = b;
  map[2] = c;
  int n = 3, m = 5;
  double **converted = convertMap(map, n, m);
  for(int i=0; i<n; i++) {
    printf("[ ");
    for(int j=0; j<m-1; j++) {
      printf("%.2f ", converted[i][j]);
    }
    printf("%.2f]\n", converted[i][m-1]);
  }

  return 0;
}
