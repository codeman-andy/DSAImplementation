#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "util.h"

/*
*array: Iterable to be sorted
length: Size of the iterable

Performs a merge-type sort on the input array of size length.
*/
extern int* mergeSort(int* array, size_t length);

#endif