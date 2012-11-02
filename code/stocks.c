#include <stdlib.h>

#include "subarray.h"
#include "stocks.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/** Divide & Conquer approach */
int stocks_dc(int *array, int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return MAX(array[0], 0);
  }
  int half = n / 2;
  int left_stocks = stocks_dc(array, half);
  int right_stocks = stocks_dc(array + half, n - half);
  int left_min = array[0];
  for (int i = 0; i < half; i++) {
    left_min = MIN(left_min, array[i]);
  }
  int right_max = array[half];
  for (int i = half; i < n; i++) {
    right_max = MAX(right_max, array[i]);
  }
  int mid_stocks = right_max - left_min;
  return MAX(left_stocks, MAX(right_stocks, mid_stocks));
}

/** Dynamic programming approach by using reduction */
int stocks(int *array, int n) {
  int *deltas = (int *) malloc(n * sizeof(int));
  deltas[0] = 0;
  for (int i = 1; i < n; i++) {
    deltas[i] = array[i] - array[i-1];
  }
  int best = maximal_subarray(deltas, n);
  free(deltas);
  return best;
}
