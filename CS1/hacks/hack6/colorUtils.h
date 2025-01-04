/**
 * Prisha Sabherwal
 * 2024/10/10
 * A collection of utility functions
 */


#ifndef MODE_H
#define MODE_H

typedef enum {
  NO_ERROR,
  OUT_OF_RANGE,
  INVALID_INPUT
} Error;

#endif /* MODE_H */

/**
 * Returns the maximum value among the three
 * given integer values.
 */
double max(double x, double y, double z);

/**
 * a function to convert from an RGB color model to CMYK
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * a function to convert from CMYK to RGB
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);



