#ifndef __LIB_H
#define __LIB_H

/** Returns an array of @a n items in the range [- n/2, n - n/2), sorted. */
void make_list(int *array, int n);

/** Prints the array */
void print_list(int *array, int n);

/** Parses the arguments and sets the values of @a num_items and @a seed.
 * Exits with status code -1 if the program does not follow the expected usage:
 *
 * Expected usage: ./prog num_items [seed]
 *
 * @param[in] argc size of @a argv
 * @param[in] argv argument vector containing our command line args
 * @param[out] num_items will be set to argv[1]
 * @param[out] seed will be set to argv[2] if set, or time(NULL). */
void parse_args(int argc, char **argv, int *num_items, unsigned *seed);

#endif
