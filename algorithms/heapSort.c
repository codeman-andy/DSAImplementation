#include "heapSort.h"



bool __noChildren(int index, size_t length) {
    return ( (index + 1) * 2 > length);
}

bool __oneChild(int index, size_t length) {
    return ( (index + 1) * 2 == length);
}

bool __maxHeapified(int* array, int index) {
    return ( (array[index] > array[(index * 2) + 1]) && (array[index] > array[(index * 2) + 2]) );
}

bool __leftGreater(int* array, int index) {
    return( (array[(index * 2) + 1] > array[index]) && (array[(index * 2) + 1] > array[(index * 2) + 2]) );
}

bool __childIsGreater(int* array, int index) {
    return(array[(index * 2) + 1] > array[index]);
}

void maxHeapify(int* array, int index, size_t length) {
    if (__noChildren(index, length)) return;
    if (__oneChild(index, length)) {
        if (__childIsGreater(array, index)) swap(array + index, array + (index * 2 + 1));
        return;
    }
    if (__maxHeapified(array, index)) return;
    if (__leftGreater(array, index)) {
        swap(array + index, array + (index * 2 + 1));
        maxHeapify(array, index * 2 + 1, length);
    }
    else {
        swap(array + index, array + (index * 2 + 2));
        maxHeapify(array, index * 2 + 2, length);
    }
}

void buildMaxHeap(int* array, size_t length) {
    for(int i = (length - 1) / 2; i >= 0; i--) {
        maxHeapify(array, i, length);
    }
}

void heapSort(int* array, size_t length) {
    buildMaxHeap(array, length);
    printf("Here is my maxHeap\n");
    printArray(array, length);
    size_t heap_size = (length - 1);
    printf("Starting... \n");
    while (heap_size > 0) {
        swap(array, array + heap_size);
        printf("Swapped: \n");
        printArray(array, length);
        maxHeapify(array, 0, heap_size);
        printf("After maxHeapify\n");
        printArray(array, length);
        heap_size--;
    }
}

int main() {
    int my_array[] = {3, 1, 7, 12, 2, 7, 10, 6, 5};
    printf("This is my array:\n");
    printArray(my_array, 9);

    printf("Max element in array is: %d\n", my_array[0]);

    heapSort(my_array, 9);
    printArray(my_array, 9);
    return 0;
}