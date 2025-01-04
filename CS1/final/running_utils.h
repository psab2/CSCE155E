/**
 * Author: Prish Sabherwal
 * 2024/12/16
 * A collection of utility functions for the NighKey running app.
 */

/**
 * Represents a single data point sample from the running app.
 */
typedef struct {
    double latitude;
    double longitude;
    double elevation;
    char datetime[20];
} RunDataPoint;

#define RADIUS_OF_EARTH 6371;

/**
 * Initializes the given RunDataPoint with the given data.
 */
void initRunDataPoint(RunDataPoint *point, double latitude, double longitude, double elevation, const char *datetime);

/**
 * Prints the given RunDataPoint to the standard output.
 */
void printRunDataPoint(const RunDataPoint *point);

/**
 * Loads an array of RunDataPoint from the given CSV file.  Reports
 * the number of points using the `numPoints` pass-by-refernce variable.
 */
RunDataPoint *loadRunDataPoints(const char *fileName, int *numPoints);

/**
 * Returns the difference in time in *seconds* betwen two ISO8601 date/time
 * formatted strings.  Will return a negative value if the second value
 * represents a time *before* the first.
 *
 * Note: this is a simple function and does not take the date into account.
 */
int timeDiff(const char *a, const char *b);

/**
 * Returns a new string formatted as "00:00:00" based on the
 * given number of seconds.  For example, if seconds = 4284,
 * it would return "01:11:24" (1 hour, 11 minutes, 24 seconds).
 */
char *formatTime(int seconds);

/**
 * Removes trailing whitespace from the given string.
 */
void rtrim(char *str);

/**
 * Sorts elevation from highets to lowest.
 */
int compareElevationAscending(const void *a, const void *b);

/**
 * Sorts time in ascending order.
 */
int compareTimeAscending(const void *a, const void *b);

/**
 * Computes the total elevation gain.
 */
double elevationGain (RunDataPoint *data, int numDataPoints);

/**
 * Calculates the distance between two points.
 */
double getAirDistance(const RunDataPoint* pointA, const RunDataPoint* pointB);

/**
 * Calculates the total distance.
 */
double totalDistance(RunDataPoint *data, int numDataPoints);

/**
 * Computes the total moving time and total wait time during the run (as defined) as well as the total time of the run.
 */
void TimeReport(RunDataPoint *data, int numDataPoints);
