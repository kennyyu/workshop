#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"
#include "shuffle.h"

void make_list(int *array, int n) {
  int half = n / 2;
  for (int i = 0; i < n; i++) {
    array[i] = i - half;
  }
}

void print_list(int *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void parse_args(int argc, char **argv, int *num_items, unsigned *seed) {
  if (argc != 3 && argc != 2) {
    fprintf(stderr, "usage: %s num_items [seed]\n", argv[0]);
    exit(-1);
  }
  *num_items = atoi(argv[1]);

  // return our seed
  if (argc == 3) {
    *seed = atoi(argv[2]);
  } else {
    *seed = time(NULL);
  }
}
