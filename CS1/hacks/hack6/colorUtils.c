/**
 * Prisha Sabherwal
 * 2024/10/10
 * the file that includes the code for the 2 functions
 */

#include "colorUtils.h"
#include <math.h>
#include <stdlib.h>

double max(double x, double y, double z) {
  double m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
  if (c == NULL || m == NULL|| y == NULL || k == NULL) {
    return INVALID_INPUT;
  }
  if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0) {
    return OUT_OF_RANGE;
  }

  if (r==0 && b==0 && g==0) {
    *c = 0;
    *m = 0;
    *y = 0;
    *k = 1;
    return NO_ERROR;
  }

    double rRange = r/255.0;
    double gRange = g/255.0;
    double bRange = b/255.0;

    *k = 1-max(rRange,gRange,bRange);
    *c = (1-rRange-(*k))/(1-(*k));
    *m = (1-gRange-(*k))/(1-(*k));
    *y = (1-bRange-(*k))/(1-(*k));

    return NO_ERROR;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
  if (r == NULL ||g == NULL|| b == NULL) {
    return INVALID_INPUT;
  }
  if (c > 1 || c < 0 || m > 1 || m < 0 || y > 1 || y < 0 || k >1 || k < 0) {
    return OUT_OF_RANGE;
  }
    *r = round(255.0*(1-(c))*(1-(k)));
    *g = round(255.0*(1-(m))*(1-(k)));
    *b = round(255.0*(1-(y))*(1-(k)));

    return NO_ERROR;
}

