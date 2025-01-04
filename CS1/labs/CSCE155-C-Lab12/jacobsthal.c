#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// computes the n-th Jacobsthal number.
int jacobsthal(int n);

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

  time_t start, end;
  start = time(NULL);
  long long result = 0;
  result = jacobsthal(n);
  end = time(NULL);

  int time = (end - start);

  printf("Jacobsthal(%d) = %lld\n", n, result);

  printf("Computation Time: %d seconds\n", time);

  return 0;
}

int jacobsthal(int n) {
  if(n==0){
    return 0;
  } else if(n==1){
    return 1;
  } else {
    return jacobsthal(n-1)+(2*(jacobsthal(n-2)));
  }
}
