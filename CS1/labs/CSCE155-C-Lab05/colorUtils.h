/**
 * Prisha Sabherwal
 * 2024/10/01
 * A collection of utility functions to manipualte RGB
 * values of an image
 */

/**
 * Scales the given rgb integer component (on the
 * scale [0, 255]) to a floating point number on the
 * scale [0, 1].
 *
 * Note: this function is only included to demonstrate
 * how to unit test floating point values.  See the
 * colorUtilsTester.c for more.
 */
double rgbIntToFloat(int c);

/**
 * Returns the maximum value among the three
 * given integer values.
 */
int max(int x, int y, int z);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the average technique.
 */
int toGrayScaleAverage(int r, int g, int b);


/**
 * function that returns the minimum of 3 integers
 */
int min(int r, int g, int b);


/**
 * function that takes three integer values (RGB values) and
 * uses the lightness technique to return the gray-scale value
 */
int toGrayScaleLightness(int r, int g, int b);


/**
 * function that takes three integer values (RGB values) and
 * uses the luminosity technique to return the gray-scale value.
 */
int toGrayScaleLuminosity(int r, int g, int b);

/**
 * sepia-tone RGB values.
 */
int toSepiaRed(int r, int g, int b);

/**
 * sepia-tone RGB values.
 */
int toSepiaGreen(int r, int g, int b);

/**
 * sepia-tone RGB values.
 */
int toSepiaBlue(int r, int g, int b);
