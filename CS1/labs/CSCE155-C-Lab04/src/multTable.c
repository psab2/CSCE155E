/**
 * Author: Prisha Sabherwal
 * Date: 2024/09/17
 *
 * This program generates a multiplication table
 * of the size given as a command line argument.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if(argc != 2) {
    printf("Error: provide an integer\n");
    exit(1);
  }

  int n = atoi(argv[1]);
  if(n <= 0) {
    printf("empty table!\n");
    exit(0);
  }

  //TODO: place your code here
  int i;
  printf("--");
  for (int i = 1; i <=n; i++) {
    printf("%d ", i );
  }
  printf("\n");
  for (int i = 1; i <= n; i++) {
    printf("%d ", i);
    for (int x = 1; x <= n; x++) {
      printf("%d ", i*x);
    }
    printf("\n");
  }

  return 0;
}
