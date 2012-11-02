#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shuffle.h"

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

  // create an array of numbers 0...n-1
  int n = atoi(argv[1]);
  int *array = (int *) malloc(n * sizeof(int));
  make_list(array, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // shuffle our array and print it out
  shuffle(array, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  free(array);
}
