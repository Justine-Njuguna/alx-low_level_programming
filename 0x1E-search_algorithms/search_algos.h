#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <math.h>

/* Prototypes for all the files */

/* Task-0 */
int linear_search(int *array, size_t size, int value);

/* Task-1 */
int binary_search(int *array, size_t size, int value);

/* Task-100 */
int jump_search(int *array, size_t size, int value);

/* Task-102 */
int interpolation_search(int *array, size_t size, int value);

/* Task-103 */
int exponential_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
