#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*array: Iterable to be sorted
length: Size of the iterable

Prints an input array of size length.
*/
extern void printArray(int* array, size_t length);

/*
*a: Pointer to the first value
*b: Pointer to the second value

Swaps the values found on the given addresses.
*/
extern void swap(int* a, int* b);

#endif