#include <stdlib.h>

#include "subarray.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/** Brute force approach */
int maximal_subarray_dumb(int *array, int n) {
  int max_sum = 0;
  for (int start = 0; start < n; start++) {
    for (int end = start; end < n; end++) {
      int sum = 0;
      for (int i = start; i <= end; i++) {
        sum += array[i];
      }
      max_sum = MAX(max_sum, sum);
    }
  }
  return max_sum;
}

/** Dynamic programming approach */
int maximal_subarray_space(int *array, int n) {
  // build out solution array
  int *subproblems = (int *) malloc(n * sizeof(int));
  subproblems[0] = MAX(array[0], 0);
  for (int i = 1; i < n; i++) {
    subproblems[i] = MAX(subproblems[i-1] + array[i], 0);
  }

  // iterate through to find the maximum
  int max = 0;
  for (int i = 0; i < n; i++) {
    max = MAX(max, subproblems[i]);
  }
  free(subproblems);
  return max;
}

/** Dynamic programming approach with optimized space usage. */
int maximal_subarray(int *array, int n) {
  int max_sum_so_far = 0;
  int current_sum_so_far = 0;
  for (int i = 0; i < n; i++) {
    current_sum_so_far = MAX(current_sum_so_far + array[i], 0);
    max_sum_so_far = MAX(max_sum_so_far, current_sum_so_far);
  }
  return max_sum_so_far;
}
