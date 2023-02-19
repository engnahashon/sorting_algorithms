#include "sort.h"

/**
 * radix_sort - sorts array of integers (ascending) by Radix sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i, max, digits, n, result = 1;
	int *output, count[10];
	unsigned int j, k;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * (int)size);
	if (output == NULL)
		return;
	for (k = 1; k < size; k++)
	{
		if (max < array[k])
			max = array[k];
	}
	for (digits = 0; max > 0; digits++)
		max /= 10;
	for (i = 0; i < digits; i++)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < size; j++)
		{
			n = (array[j] / result) % 10;
			count[n]++;
		}
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = size - 1; ((int)j >= 0); j--)
		{
			n = (array[j] / result) % 10;
			output[count[n] - 1] = array[j];
			count[n]--;
		}
		for (j = 0 ; j < size ; j++)
			array[j] = output[j];
		print_array(array, size);
		result *= 10;
	}
	free(output);
}
