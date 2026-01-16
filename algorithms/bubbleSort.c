#include "bubbleSort.h"



int* bubbleSort(int* array, size_t length) {
    size_t bubble_start = (length - 1); // Last index
    size_t REPEAT_LOOP = 1;
    
    while (REPEAT_LOOP) {
        REPEAT_LOOP = 0;

        for(int i = 0; i < bubble_start; i++) {

            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                REPEAT_LOOP = 1;
                printArray(array, length);
            }
            
        }

        if (REPEAT_LOOP) bubble_start--;

    }

    return array;
}