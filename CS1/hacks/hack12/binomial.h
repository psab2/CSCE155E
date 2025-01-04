/**Prisha Sabherwal
 * 2024/11/21
 * This is a collection of utility functions
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * takes n and k and computes using Pascal's Rule.
 */
long choose(int n, int k);

/**
 * memoization (caching) to avoid unnecessary repeated recursive calls in the choose function
 */
long chooseMemoization(int n, int k, long **cache);
