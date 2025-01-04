/**
 * Prisha Sabherwal
 * 2024/10/03
 * A collection of utility functions
 */

/**
 * a function to convert degrees to radians
 */
double degreesToRadians(double degree);


/**
 * compute the air distance between two locations identified by
 * their latitude/longitude
 */
double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude);

/**
 * compute the dilated time given the normal time 𝑡
 * (units may vary) and the percentage of the speed of light
 */
double lorentzTimeDilation(double t, double percentC);

