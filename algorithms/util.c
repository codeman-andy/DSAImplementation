#include "util.h"

void printArray(int* array, size_t length) {
    printf("Array: ");
    for(int i = 0; i < length; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}