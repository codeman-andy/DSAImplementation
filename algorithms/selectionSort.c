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

/*
int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printArray(array, length);
    int* sorted_array = selection(array, length);
    printArray(sorted_array, length);
    return 0;
}*/