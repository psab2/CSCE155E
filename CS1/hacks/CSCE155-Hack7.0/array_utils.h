/**
 * Prisha Sabherwal
 * 2024/10/17
 * A collection of function prototypes
 */

/**
 * a function that, given an integer array and an integer x
 * determines if the array contains x anywhere within the array.
 * It should return true if it does, false otherwise.
 */
int contains(const int *arr, int size, int x);

/**
 * a function that, given an integer array and an integer x,
 * determines if the array contains x within the range of the
 * two provided indices i;and;j(including both indices).
 * It should return true if it does, false otherwise.
 */
int containsWithin(const int *arr, int size, int x, int i, int j);

/**
 * a function that, given an array of integers, its size
 * and a "new size" creates a new deep copy of the array. However,
 * instead of its original size, the new array should be of the new size.
 * If the new size is less than the old size, only the first newSize
 * elements should be copied over. If the new size is greater than the
 * original size, then the new array should be padded out with zeros.
 */
int * paddedCopy(const int *arr, int oldSize, int newSize);

/**
 * a function that, given an array of integers and
 * its size, reverses the elements in the array. For example,
 * if the original array was [10, 15, 5, 25, 0] the new array
 * should be [0, 25, 5, 15, 10].
 */
void reverse(int *arr, int size);

/**
 * a similar function that creates and returns a new copy of
 * the given array but with its elements in reverse order.
 */
int * reverseCopy(const int *arr, int size);
