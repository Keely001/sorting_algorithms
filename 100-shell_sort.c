#include "sort.h"

/**
 * shell_sort - shell sort algorithm
 * @array: array of integers.
 * @size: size of array.
 */
 void shell_sort(int *array, size_t size) {
    int interv = 1;
    while (interv <= size / 3)
        interv = interv * 3 + 1;
    while (interv > 0) {
        for (int a = interv; a < size; a++) {
            int temp = array[a];
            int j;
            for (j = a; j >= interv && array[j - interv] > temp; j -= interv) {
                array[j] = array[j - interv];
            }
            array[j] = temp;
        }
        interv = (interv - 1) / 3;
        print_array(array, size);
    }
}