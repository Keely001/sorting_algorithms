#include "sort.h"
/**
 * selection_sort - sorts using the selection method.
 * @array: integers array
 * @size: size of array
 * Return: None.
 */
 void selection_sort(int *array, size_t size) {
    size_t i, j, min_ind, tmp;

    for (i = 0; i < size - 1; i++) {
        min_ind = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            tmp = array[i];
            array[i] = array[min_ind];
            array[min_ind] = tmp;
            print_array(array,size);
        }
    }
}