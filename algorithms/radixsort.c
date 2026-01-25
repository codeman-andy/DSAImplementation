#include <stdio.h>
#include <stdlib.h>

#include "bucketSort.h"
#include "util.h"

/*
*array: An unsorted array
length: The length of the array
range: The number of bits of the values in the array

Performs a radix-type sort on the input array of size length with values of size up to range.
*/
void radixSort(int* array, size_t length, size_t base, size_t range) {
    size_t number_of_buckets = base;
    int* numbers_in_bucket = (int*) calloc(number_of_buckets, sizeof(int)); // Keeps track of how many numbers fall into each bucket

    int base_scaled = base; // base_scaled will iterate over the different powers of the base until it surpasses the range
    int prev_base = 1; // prev_base will store the previous value for the base_scaled variable
    while (base_scaled <= range) {
        for(int i = 0; i < length; i++) {
            numbers_in_bucket[(array[i] % base_scaled) / prev_base]++;
        }
        
        int* buckets[number_of_buckets];
        for(int i = 0; i < number_of_buckets; i++) {
            buckets[i] = (int*) calloc(numbers_in_bucket[i], sizeof(int));
        }

        // Place each value in array to one of the buckets
        int copy_of_numbers_in_bucket[number_of_buckets];
        memcpy(copy_of_numbers_in_bucket, numbers_in_bucket, number_of_buckets * sizeof(int));
        int bucket; // Into which bucket will each entry fall in to
        for(int j = 0; j < length; j++) {
            bucket = array[j] % base_scaled / prev_base;
            buckets[bucket][copy_of_numbers_in_bucket[bucket] - 1] = array[j];
            copy_of_numbers_in_bucket[bucket]--;
        }
        
        // Output the ordered values from the buckets back into the array
        int index = 0;
        for(int j = 0; j < number_of_buckets; j++) {
            while (numbers_in_bucket[j] > 0) {
                array[index] = buckets[j][numbers_in_bucket[j] - 1];
                index++;
                numbers_in_bucket[j]--;
            }
        }
        
        prev_base = prev_base * base;
        base_scaled = base_scaled * base;
        for(int i = 0; i < number_of_buckets; i++) {
            free(buckets[i]);
        }
    }
}

int main() {
    int my_array[] = {18, 43, 55, 51, 14, 7, 26, 72, 99};
    printf("This is my array:\n");
    printArray(my_array, 9);

    radixSort(my_array, 9, 10, 100);
    printArray(my_array, 9);

    int my_array_two[] = {18, 43, 55, 51, 14, 7, 26, 72, 99};
    printf("\nNow with power-of-two\n");
    radixSort(my_array_two, 9, 2, 128);
    printArray(my_array_two, 9);

    int new_array[] = {31, 14, 27, 3, 7};
    printf("\nNew array:\n");
    printArray(new_array, 5);

    radixSort(new_array, 5, 2, 32);
    printArray(new_array, 5);
    return 0;
}