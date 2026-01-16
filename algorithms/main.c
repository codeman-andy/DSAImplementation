#include "main.h"



int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printf("Hello!\nInitially, we have the following...\n");
    printArray(array, length);
    int* selection_sorted_array = selectionSort(array, length);
    printf("After selection-sorting, we have...\n");
    printArray(selection_sorted_array, length);
    int* bubble_sorted_array = bubbleSort(array, length);
    printf("After bubble-sorting, we have...\n");
    printArray(bubble_sorted_array, length);
    int* insertion_sorted_array = insertionSort(array, length);
    printf("After insertion-sorting, we have...\n");
    printArray(insertion_sorted_array, length);
    int* merge_sorted_array = mergeSort(array, length);
    printf("After merge-sorting, we have...\n");
    printArray(merge_sorted_array, length);
    quickSort(array, 0, (length - 1) );
    printf("After quick-sorting, we have...\n");
    printArray(array, length);
    printf("That's all! Take care!\n");

    return 0;
}