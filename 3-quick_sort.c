#include "sort.h"

void swap_ints(int *a, int *b);
int lomutoscheme_partition(int *array, size_t size, int left, int right);
void lomutoscheme_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Exchange the positions of two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomutoscheme_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of ints.
 * @size: The array's size.
 * @left: The initiating index of the ordered subset.
 * @right: The final index of the ordered subset.
 * Return: The final partition index.
 */
int lomutoscheme_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomutoscheme_sort - Executes the quicksort algo recursively.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 *
 * Description: Utilizes the Lomuto partition scheme.
 */
void lomutoscheme_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomutoscheme_partition(array, size, left, right);
		lomutoscheme_sort(array, size, left, part - 1);
		lomutoscheme_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Arrange an array of integers in ascending order
 * using the quicksort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the quicksort algorithm with the
 * Lomuto partition scheme. Prints the array after
 * each pairwise element swap operation.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoscheme_sort(array, size, 0, size - 1);
}
