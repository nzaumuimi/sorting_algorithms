#include "sort.h"

/**
 * exchange_ints - Swaps 2 ints in an array.
 * @a: The 1st int to swap.
 * @b: The 2nd int to swap.
 */
void exchange_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of ints in ascending
 *              order using shell sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				exchange_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}

