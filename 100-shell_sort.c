#include "sort.h"

/**
 * shell_sort -  sorts array of integers (ascending) by Shell sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		/* Knuth sequence */
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			/* insertion sort here */
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j = j - interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		/* print the array each interval decrease */
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
