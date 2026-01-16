#include "quickSort.h"

int __partition(int* array, int start, int end) {
    int pivot = array[end];
    int partition_index = start;
    for(int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            swap(&array[i], &array[partition_index]);
            partition_index++;
        }
    }
    swap(&array[partition_index], &array[end]);
    return partition_index;
}

void quickSort(int* array, int start, int end) {
    if (start < end) {
        int partition_index = __partition(array, start, end);
        quickSort(array, start, (partition_index - 1) );
        quickSort(array, (partition_index + 1), end);
    }
}

/*
int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printArray(array, length);
    quick(array, 0, (length - 1) );
    printArray(array, length);
    return 0;
}*/