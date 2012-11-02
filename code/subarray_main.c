#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shuffle.h"
#include "subarray.h"

int main(int argc, char **argv) {
  if (argc != 3 && argc != 2) {
    fprintf(stderr, "usage: %s num_items [seed]\n", argv[0]);
    exit(-1);
  }

  // seed our random number generator
  if (argc == 3) {
    srand(atoi(argv[2]));
  } else {
    srand(time(NULL));
  }

  // create an array of numbers 0...n-1 and shuffle the list
  int n = atoi(argv[1]);
  int *array = (int *) malloc(n * sizeof(int));
  make_list(array, n);
  shuffle(array, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("maximal subarray dumb sum: %d\n", maximal_subarray_dumb(array, n));
  printf("maximal subarray sp.  sum: %d\n", maximal_subarray_space(array, n));
  printf("maximal subarray dp   sum: %d\n", maximal_subarray(array, n));
  free(array);
}
