#include "sort.h"


void swap_int(int *a, int *b);
/**
 * swap_int - swap two int.
 * @a: first integer
 * @b: second integer.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * shell_sort - an array of integers in ascending.
 * @array: array of integers
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_int(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}