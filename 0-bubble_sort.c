#include "sort.h"
/**
 * bubble_sort - sorts array of integers (ascending) by Bubble sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, n;
	int tmp;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{

		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		n--;
	}
}
