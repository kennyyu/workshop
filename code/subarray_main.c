#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"
#include "shuffle.h"
#include "subarray.h"

int main(int argc, char **argv) {
  int n = 0;
  unsigned seed = 0;
  parse_args(argc, argv, &n, &seed);
  srand(seed);

  int *array = (int *) malloc(n * sizeof(int));
  make_list(array, n);
  shuffle(array, n);
  print_list(array, n);

  printf("maximal subarray dumb sum: %d\n", maximal_subarray_dumb(array, n));
  printf("maximal subarray sp.  sum: %d\n", maximal_subarray_space(array, n));
  printf("maximal subarray dp   sum: %d\n", maximal_subarray(array, n));
  free(array);
}
