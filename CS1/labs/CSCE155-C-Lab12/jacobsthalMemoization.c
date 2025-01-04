#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Computes the n-th Jacobsthal number using an iterative
 * method
 */
long long jacobsthalIterative(int n);


//naive recursive function using memoization
long jacobsthal(int n, long *cache);

/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 *
 */
int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  long *cache = (long *) malloc (sizeof(long) * (n + 1));
  for(int i=0; i<(n+1); i++){
    cache[i] = -1;
  }

  cache[0] = 0;
  cache[1] = 1;

  time_t start, end;
  long long iterativeResult = jacobsthalIterative(n);

  start = time(NULL);

  long long memoizationResult = jacobsthal(n, cache);

  end = time(NULL);

  int time = (end - start);

  printf("Iterative:   Jacobsthal(%d) = %lld\n", n, iterativeResult);
  printf("Memoization: Jacobsthal(%d) = %lld\n", n, memoizationResult);

  printf("Total Computation Time: %d seconds\n", time);

  return 0;
}

long jacobsthal(int n, long *cache) {
  if(n==0){
    return 0;
  } else if(n==1){
    return 1;
  } else {
    if(cache[n] != -1) {
      return cache[n];
    } else {
      long x = jacobsthal(n-1, cache)+(2*(jacobsthal(n-2, cache)));
      cache[n]=x;
      return x;
    }
  }
}

long long jacobsthalIterative(int n) {
  if(n <= 1) {
    return n;
  }
  long long prev = 0;
  long long curr = 1;
  for(int i=2; i<=n; i++) {
    long long t = 2 * prev + curr;
    prev = curr;
    curr = t;
  }
  return curr;
}
