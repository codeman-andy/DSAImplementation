#include "insertionSort.h"

 /*First attempt
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


int* insertionSort(int* array, size_t length) {
    for(int unsorted = 1; unsorted < length; unsorted++) {
        int to_insert = unsorted;

        while( ((to_insert - 1) >= 0) && (array[to_insert - 1] > array[to_insert]) ) {
            swap(&array[to_insert - 1], &array[to_insert]);
            to_insert--;
        }

    }

    return array;
}

/*
int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printArray(array, length);
    int* sorted_array = insertion(array, length);
    printArray(sorted_array, length);
    return 0;
}*/