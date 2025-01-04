#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int *r, int *g, int *b, Mode mode) {
  if (r == NULL || g == NULL || b == NULL) {
    return INVALID_INPUT;
  }
  if (*r > 255 || *r < 0 || *g > 255 || *g < 0 || *b > 255 || *b < 0) {
    return OUT_OF_RANGE;
  }
  if (mode == AVERAGE) {
    int grayScaleAvg = round((*r + *g + *b) / 3.0);
    *r = grayScaleAvg;
    *g = grayScaleAvg;
    *b = grayScaleAvg;
  }
  else if (mode == LIGHTNESS) {
    int grayScaleLight = round((max(*r,*g,*b)+min(*r,*g,*b))/2.0);
    *r = grayScaleLight;
    *g = grayScaleLight;
    *b = grayScaleLight;
  }
  else if (mode == LUMINOSITY) {
    int grayScaleLuminosity = round(0.21 * (*r) + 0.72 * (*g) + 0.07 * (*b));
    *r = grayScaleLuminosity;
    *g = grayScaleLuminosity;
    *b = grayScaleLuminosity;
  }
  else {
    return INVALID_INPUT;
  }
  return NO_ERROR;
}

int toSepia(int *r, int *g, int *b) {
  if (r == NULL || g == NULL || b == NULL) {
    return INVALID_INPUT;
  }
  if (*r > 255 || *r < 0 || *g > 255 || *g < 0 || *b > 255 || *b < 0) {
    return OUT_OF_RANGE;
  }
    double sepiaR = round(0.393 * (*r) + 0.769 * (*g) + 0.189 * (*b));
    double sepiaG = round(0.349 * (*r) + 0.686 * (*g) + 0.168 * (*b));
    double sepiaB = round(0.272 * (*r) + 0.534 * (*g) + 0.131 * (*b));
    *r = sepiaR;
    *g = sepiaG;
    *b = sepiaB;
    return NO_ERROR;
}
