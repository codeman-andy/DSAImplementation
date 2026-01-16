#include "selectionSort.h"



int* selectionSort(int* array, size_t length) {
    for(int i = 0; i < (length - 1); i++) {
        int j = i;
        int* min = &array[j];
        while (j < (length - 1)) {
            j++;
            if (array[j] < *min) min = &array[j];
        }
        if (array[i] != *min) swap(&array[i], min);
    }

    return array;
}