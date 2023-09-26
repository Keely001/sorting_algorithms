#include "sort.h"

void swap_int(int *fst, int *scd);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_int - implements the swapping mechanism
 * @fst: fst integer
 * @scd: scd integer
 */
void swap_int(int *fst, int *scd)
{
	int temp;

	temp = *fst;
	*fst = *scd;
	*scd = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of int.
 * @size: size of array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pvt, higher, lower;

	pvt = array + right;
	for (higher = lower = left; lower < right; lower++)
	{
		if (array[lower] < *pvt)
		{
			if (higher < lower)
			{
				swap_int(array + lower, array + higher);
				print_array(array, size);
			}
			higher++;
		}
	}

	if (array[higher] > *pvt)
	{
		swap_int(array + higher, pvt);
		print_array(array, size);
	}
	return (higher);
}

/**
 * lomuto_sort - quicksort using recursion.
 * @array: array of int
 * @size: size of int
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int section;

	if (right - left > 0)
	{
		section = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, section - 1);
		lomuto_sort(array, size, section + 1, right);
	}
}

/**
 * quick_sort - the quick sorting algorithm
 * @array: array of int
 * @size: size of int
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}