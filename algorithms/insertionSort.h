#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "util.h"

/*
*array: Iterable to be sorted
length: Size of the iterable

Performs an insert-type sort on the input array of size length.
*/
extern int* insertionSort(int* array, size_t length);

#endif