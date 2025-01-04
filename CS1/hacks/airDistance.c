/**
 * Author: Prisha
 * Date: 2024/09/15
 *
 * This program interactively prompts the user to enter the latitude and longitude of
 * two locations and then computes the distance between them using the Spherical Law of Cosines.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double latitude_loc_a, latitude_loc_b, longitude_loc_a, longitude_loc_b;

  printf("Please enter the latitude of location a: ");
  scanf("%lf", &latitude_loc_a);
  double rlat_a = ((latitude_loc_a/180)*M_PI);

  printf("Please enter the latitude of location b: ");
  scanf("%lf", &latitude_loc_b);
  double rlat_b = ((latitude_loc_b/180)*M_PI);

  printf("Please enter the longitude of location a: ");
  scanf("%lf", &longitude_loc_a);
  double rlong_a = ((longitude_loc_a/180)*M_PI);

  printf("Please enter the longitude of location b: ");
  scanf("%lf", &longitude_loc_b);
  double rlong_b = ((longitude_loc_b/180)*M_PI);

  double diff_in_longs;
  diff_in_longs = (rlong_b - rlong_a);

  double distance;
  distance = acos((sin(rlat_a)*sin(rlat_b))+(cos(rlat_a)*cos(rlat_b)*cos(diff_in_longs)))*6371;

  printf("Air distance is %.6f\n", distance);

  return 0;
}
