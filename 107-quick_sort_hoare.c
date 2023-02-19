#include "sort.h"

/**
 * partition - target of partitions is, given an array and an element x
 * of an array as the pivot, put x at its correct position in a sorted
 * array and put all smaller elements (smaller than x) before x, and
 * put all greater elements (greater than x) after x
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: array size
 * Return: partitioning index
 */
int partition(int *array, int low, int high, size_t size)
{
	/* pivot (Element to be placed at right position) */
	int tmp, pivot = array[high];

	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				tmp = array[low];
				array[low] = array[high];
				array[high] = tmp;
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
 * quickSort - picks an element as a pivot and partitions the given
 * array around the picked pivot
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: array size
 * Return: void
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/* pi is partitioning index, array[pi] is now at right place */
		pi = partition(array, low, high, size);
		quickSort(array, low, pi, size);    /* Before pi */
		quickSort(array, pi + 1, high, size);   /* After pi */
	}
}

/**
 * quick_sort_hoare -sorts array of integers(ascending) by Quick sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, (int)size - 1, size);
}
