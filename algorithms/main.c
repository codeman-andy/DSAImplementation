#include "main.h"



int main() {
    int initial_array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(initial_array) / sizeof(*initial_array);

    printf("Hello!\nInitially, we have the following...\n");
    printArray(initial_array, length);

    int bubble_array[length];
    memcpy(bubble_array, initial_array, sizeof(*initial_array) * length);
    printf("\nBubble-sorting...\n");
    int* bubble_sorted_array = bubbleSort(bubble_array, length);
    printf("Final result...\n");
    printArray(bubble_sorted_array, length);

    int selection_array[length];
    memcpy(selection_array, initial_array, sizeof(*initial_array) * length);
    printf("\nSelection-sorting...\n");
    int* selection_sorted_array = selectionSort(selection_array, length);
    printf("Final result...\n");
    printArray(selection_sorted_array, length);

    int insertion_array[length];
    memcpy(insertion_array, initial_array, sizeof(*initial_array) * length);
    printf("\nInsertion-sorting...\n");
    int* insertion_sorted_array = insertionSort(insertion_array, length);
    printf("Final result...\n");
    printArray(insertion_sorted_array, length);

    int merge_array[length];
    memcpy(merge_array, initial_array, sizeof(*initial_array) * length);
    printf("\nMerge-sorting...");
    int* merge_sorted_array = mergeSort(merge_array, length);
    printf("Final result...\n");
    printArray(merge_sorted_array, length);

    int quick_array[length];
    memcpy(quick_array, initial_array, sizeof(*initial_array) * length);
    printf("\nQuick-sorting...\n");
    quickSort(quick_array, 0, (length - 1) );
    printf("Final result...\n");
    printArray(quick_array, length);

    printf("\nThat's all! Take care!\n");

    return SUCCESS;
}