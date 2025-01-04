/**Prisha Sabherwal
 * 2024/11/21
 * Functions implemented
 */
#include <stdlib.h>
#include <stdio.h>
#include "binomial.h"

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("error, enter enough arguments\n");
    exit(1);
  }
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  long **cache = (long **) malloc((n + 1) * sizeof(long *));
  for (int i = 0; i <= n; i++) {
    cache[i] = (long *) malloc((k + 1) * sizeof(long));
    for (int j = 0; j <= k; j++) {
      cache[i][j] = -1;
    }
  }

  long memoizationResult = chooseMemoization(n, k, cache);

  printf("Memoization: choose(%d, %d) = %ld\n", n, k, memoizationResult);

  for (int i = 0; i <= n; i++) {
    free(cache[i]);
  }
  free(cache);

  return 0;
}
