#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 * @array: input arrray
 * @size: size of array
 * Return: Non
 */

void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j;
	int signal;

	for (i = 0; i < size ; i++)
	{
		signal = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				signal = 1;
			}
		}
		if (signal == 0)
			break;
	}
}
