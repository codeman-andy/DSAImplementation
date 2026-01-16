#include "selectionSort.h"



int* selectionSort(int* array, size_t length) {
    for(int i = 0; i < (length - 1); i++) {
        printArray(array, length);
        int j = i;
        int* minimum_value = &array[j];
        while (j < (length - 1)) {
            j++;
            if (array[j] < *minimum_value) minimum_value = &array[j];
        }
        if (array[i] != *minimum_value) swap(&array[i], minimum_value);
    }

    return array;
}