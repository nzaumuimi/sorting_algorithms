#include "sort.h"

/**
 * exchange_ints - Exchange the values of two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void exchange_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Arrange an array of integers in ascending order
 * using the selection sort algorithm.
 *
 * @array: An array of ints.
 * @size: The array's size.
 *
 * Description: Displays the array after each swapping operation.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t n, m;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		min = array + n;
		for (m = n + 1; m < size; m++)
			min = (array[m] < *min) ? (array + m) : min;

		if ((array + n) != min)
		{
			exchange_ints(array + n, min);
			print_array(array, size);
		}
	}
}
