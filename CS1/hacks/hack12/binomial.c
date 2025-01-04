/**Prisha Sabherwal
 * 2024/11/21
 * This is a collection of function definitions
 */
#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

long choose(int n, int k) {
  if(k==0){
    return 1;
  } else if(n==k){
    return 1;
  } else {
    return choose(n - 1, k - 1) + choose(n - 1, k);
  }
}

long chooseMemoization(int n, int k, long **cache) {
  if(k==0){
    return 1;
  } else if(n==k){
    return 1;
  } else {
    if(cache[n][k] != -1) {
      return cache[n][k];
    } else {
      return cache[n][k] = chooseMemoization(n - 1, k - 1, cache) + chooseMemoization(n - 1, k, cache);
    }
  }
}
