#include "sort.h"

/**
 * swap_ints - Swaps 2 ints in an array.
 *
 * @a: Pointer to the 1st integer to be swapped.
 * @b: Pointer to the 2nd integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Arrange an array of integers in ascending
 * order using the bubble sort algorithm.
 *
 * @array: The array of ints to be sorted.
 * @size: The array's size
 *
 * Description: Prints the array after each swapping operation.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
