#include "insertionSort.h"



int* insertionSort(int* array, size_t length) {
    printArray(array, length);

    for(int unsorted_start = 1; unsorted_start < length; unsorted_start++) {
        int to_insert = unsorted_start;

        while( ((to_insert - 1) >= 0) && (array[to_insert - 1] > array[to_insert])) {
            swap(&array[to_insert - 1], &array[to_insert]);
            to_insert--;
            printArray(array, length);
        }

    }

    return array;
}

/* First attempt
int* insertion(int* array, size_t length) {
    for(int unsorted = 1; unsorted < length; unsorted++) {

        for(int sorted = 0; sorted < unsorted; sorted++) {

            if (array[unsorted] < array[sorted]) {
                int to_insert = unsorted;

                while (to_insert != sorted) {
                    swap(&array[to_insert], &array[to_insert - 1]);
                    to_insert--;
                }

                break;
                }

            }

        }

    return array;
}
*/