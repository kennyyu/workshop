#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"
#include "shuffle.h"

int main(int argc, char **argv) {
  int n = 0;
  unsigned seed = 0;
  parse_args(argc, argv, &n, &seed);
  srand(seed);

  int *array = (int *) malloc(n * sizeof(int));
  make_list(array, n);
  print_list(array, n);

  // shuffle our array and print it out
  shuffle(array, n);
  print_list(array, n);
  free(array);
}
