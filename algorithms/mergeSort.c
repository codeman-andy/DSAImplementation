#include "mergeSort.h"

int* mergeSort(int* array, size_t length) {
    if (length == 1) {
        return array;
    }

    int half_point = length / 2;
    int left[half_point];
    int right_length = length - half_point;
    int right[right_length];

    int i = 0;
    while (i != half_point) {
        left[i] = array[i];
        right[i] = array[half_point + i];
        i++;
    }
    if (right_length != half_point) right[i] = array[half_point + i]; // For odd-size arrays
    
    int* left_sorted = mergeSort(left, half_point);
    int* right_sorted = mergeSort(right, right_length);

    int* sorted_array = (int*) calloc(length, sizeof(int));
    int left_index, right_index, arr_index;
    left_index = right_index = arr_index = 0;
    while (left_index < half_point && right_index < right_length) {
        if (left_sorted[left_index] <= right_sorted[right_index]) {
            sorted_array[arr_index] = left_sorted[left_index];
            left_index++;
        }
        else {
            sorted_array[arr_index] = right_sorted[right_index];
            right_index++;
        }
        arr_index++;
    }
    while (left_index < half_point) {
        sorted_array[arr_index] = left_sorted[left_index];
        arr_index++;
        left_index++;
    }
    while (right_index < right_length) {
        sorted_array[arr_index] = right_sorted[right_index];
        arr_index++;
        right_index++;
    }

    free(left_sorted);
    free(right_sorted);

    return sorted_array;
}

/*
int main() {
    int array[] = {2, 7, 4, 1, 5, 3};
    size_t length = sizeof(array) / sizeof(*array);
    printArray(array, length);
    int* sorted_array = merge(array, length);
    printArray(sorted_array, length);
    return 0;
}*/