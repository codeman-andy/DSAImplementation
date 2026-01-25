#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

/*
Performs a heap-sort on an unordered array.
*/
extern void heapSort(int* array, size_t length);

#endif