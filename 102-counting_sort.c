#include "sort.h"

/**
 * secure_maximum - gets the maximum value in an array of ints.
 * @array: An array of ints.
 * @size: The erray's maximum int.
 *
 * Return: The maximum int in the array.
 */
int secure_maximum(int *array, int size)
{
	int max, q;

	for (max = array[0], q = 1; q < size; q++)
	{
		if (array[q] > max)
			max = array[q];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of int's in ascending order
 * using the counting sort algorithm.
 * @array: An array of ints.
 * @size: The array's size.
 *
 * Description: Sets up a counting array and prints it.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, q;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = secure_maximum(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (q = 0; q < (max + 1); q++)
		count[q] = 0;
	for (q = 0; q < (int)size; q++)
		count[array[q]] += 1;
	for (q = 0; q < (max + 1); q++)
		count[q] += count[q - 1];
	print_array(count, max + 1);

	for (q = 0; q < (int)size; q++)
	{
		sorted[count[array[q]] - 1] = array[q];
		count[array[q]] -= 1;
	}

	for (q = 0; q < (int)size; q++)
		array[q] = sorted[q];

	free(sorted);
	free(count);
}
