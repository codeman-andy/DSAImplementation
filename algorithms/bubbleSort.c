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

/*
int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printArray(array, length);
    int* sorted_array = bubble(array, length);
    printArray(sorted_array, length);
    return 0;
}*/