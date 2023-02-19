#include "sort.h"
/**
 * print_range - print a range
 * @array: array
 * @r: range
 * @r1: other range
 * Return: void
 */
void print_range(int *array, int r, int r1)
{
	int i;

	for (i = r; i <= r1; i++)
	{
		if (i > r)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * compAndSwap - swaps two elements in an array
 * @a: array
 * @i: an index
 * @j: other index
 * @dir: the sorting direction (ascending / descending)
 * if (a[i] > a[j]) agrees with the direction,
 * then a[i] and a[j] are interchanged.
 * Return: void
 */
void compAndSwap(int a[], int i, int j, int dir)
{
	int tmp;

	if (dir == (a[i] > a[j]))
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

/**
 * bitonicMerge - It recursively sorts a bitonic sequence in ascending order
 * if dir = 1, and in descending order otherwise (means dir=0).
 * @a: array
 * @low: index position low, where the sequence to be sorted starts at
 * @n: the number of elements to be sorted
 * @dir: the sorting direction
 * @N: array size
 * Return: void
 */
void bitonicMerge(int a[], int low, int n, int dir, const int N)
{
	int k, i;

	if (n > 1)
	{
		k = n / 2;
		for (i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);
		bitonicMerge(a, low, k, dir, N);
		bitonicMerge(a, low + k, k, dir, N);
	}
}

/**
 * bitonicSort - This function first produces a bitonic sequence by recursively
 * sorting its two halves in opposite sorting orders, and then
 * calls bitonicMerge to make them in the same order
 * @a: array
 * @low: index position low, where the sequence to be sorted starts at
 * @n: the number of elements to be sorted
 * @dir: the sorting direction
 * @N: array size
 * Return: void
 */
void bitonicSort(int a[], int low, int n, int dir, const int N)
{
	int k = n;

	if (n > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", n, N);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", n, N);
		print_range(a, low, low + k - 1);

		k = n / 2;
		/* sort in ascending order since dir here is 1 */
		bitonicSort(a, low, k, 1, N);

		/* sort in descending order since dir here is 0 */
		bitonicSort(a, low + k, k, 0, N);

		/* Will merge whole sequence in ascending order since dir=1. */
		bitonicMerge(a, low, n, dir, N);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", n, N);
			print_range(a, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", n, N);
			print_range(a, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - Caller of bitonicSort for sorting the entire array of
 * length N in ASCENDING order
 * @array: array
 * @size: array size
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int N = (int)size;

	if (array == NULL || N < 2)
		return;
	bitonicSort(array, 0, (int)size, up, N);
}
