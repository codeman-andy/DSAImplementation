#include "bubbleSort.h"



int* bubbleSort(int* array, size_t length) {
    size_t _bubble = length;
    size_t signal = 1;

    while (signal) {
        signal = 0;
        for(int i = 0; i < (_bubble - 1); i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                signal = 1;
            }
        }
        if (signal == 1) _bubble--;        
    }

    return array;
}