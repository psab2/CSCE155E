/**
 * A collection of array and 2-D array utility
 * functions.
 */

/**
 * Prints the given integer array to the standard output
 */
void printArray(const int *arr, int n);

/**
 * Prints the given (n x m) integer table to the standard
 * output.
 */
void printTable(int **table, int n, int m);

/**
 * Generates an array of integers of the given size filled
 * with random integer values between 0 and 100 (exclusive).
 * This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);

/**
 * Sums the elements in the given array.
 */
int getSum(const int *arr, int size);

/**
 * Frees the given (n x m) table.  Only the first parameter
 * (n, number of rows) is necessary to free the table.
 */
void freeTable(int **table, int n);

/**
 * computes the average of elements in array
 */
double getMean(const int *arr, int size);

/**
 * returns the minimum element in array
 */
int getMin(const int *arr, int size);

/**
 * returns the index of the the minimum element in array
 */
int getIndexOfMin(const int *arr, int size);

/**
 * returns the maximum element in array
 */
int getMax(const int *arr, int size);

/**
 * returns the index of the the maximum element in array
 */
int getIndexOfMax(const int *arr, int size);

/**
 * creates and returns a new array that contains elements in array
 * that are greater than or equal to threshold.
 */
int * filterThreshold(const int *arr, int size, int threshold, int *resultSize);

/**
 * creates and returns a new (n x m) 2-D array that contains the values
 * in a multiplication table
 */
int **createMultiplicationTable(int n, int m);
