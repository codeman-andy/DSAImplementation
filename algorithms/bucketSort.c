#include "bucketSort.h"

/*
*array: An unsorted array
length: The length of the array
range: The range for the values found in the array. For optimal performance, you should use the max value in the array + 1
*/
void bucketSort(int* array, size_t length, size_t range) {
    int buckets[range];
    for(int i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    for(int i = 0; i < length; i++) {
        buckets[array[i]]++;
    }

    int index = 0;
    for(int j = 0; j < range; j++) {
        while (buckets[j] > 0) {
            array[index] = j;
            index++;
            buckets[j]--;
        }
    }
}

int main() {
    int my_array[] = {3, 1, 7, 8, 2, 7, 4, 6, 5};
    printf("This is my array:\n");
    printArray(my_array, 9);

    bucketSort(my_array, 9, 10);
    printArray(my_array, 9);
    return 0;
}