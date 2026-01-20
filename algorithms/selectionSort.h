#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "util.h"

/*
*array: Iterable to be sorted
length: Size of the iterable

Performs a selection-type sort on the input array of size length.
*/
extern int* selectionSort(int* array, size_t length);

#endif