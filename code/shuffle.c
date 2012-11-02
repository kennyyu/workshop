#include <stdlib.h>

#include "shuffle.h"

/** Generates a random integer in [i, j). */
static inline int my_random(int i, int j) {
  return i + rand() % (j - i);
}

/** Swaps the values at addresses pointed to by @a x and @a y. */
static inline void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

/** Shuffles the array of length @a n such that
 * all permutations are equally likely. */
void shuffle(int *array, int n) {
  for (int i = 0; i < n; i++) {
    swap(&array[i], &array[my_random(i, n)]);
  }
}
