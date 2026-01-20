#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "util.h"

/*
*array: Iterable to be sorted
length: Size of the iterable

Performs a quick-type sort on the input array of size length.
*/
extern void quickSort(int* array, int start, int end);

#endif