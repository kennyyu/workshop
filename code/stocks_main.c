#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"
#include "shuffle.h"
#include "stocks.h"

int main(int argc, char **argv) {
  int n = 0;
  unsigned seed = 0;
  parse_args(argc, argv, &n, &seed);
  srand(seed);

  int *array = (int *) malloc(n * sizeof(int));
  make_list(array, n);
  shuffle(array, n);
  print_list(array, n);

  printf("stocks divide & conquer: %d\n", stocks_dc(array, n));
  printf("stocks reduction:        %d\n", stocks(array, n));
  free(array);
}
