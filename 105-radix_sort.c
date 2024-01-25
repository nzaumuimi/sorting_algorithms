#include "sort.h"

int secure_maximum(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * secure_maximum - Secures maximum value in an array of ints.
 * @array: An integers' array.
 * @size: The array's size.
 *
 * Return: The largest int in the array.
 */
int secure_maximum(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_count_sort - Sorts the largest digits of an array of ints
 * in ascending order using the counting sort algos.
 * @array: An integers' array.
 * @size: The array's size.
 * @sig: The biggest digit to sort on.
 * @buff: A buffer that stores the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - They sort an array of ints from smallets to
 * the largest using the radix sort algos.
 * @array: An integers' array.
 * @size: The array's size.
 *
 * Description: Operationalises the LSD radix sort algo &
 * prints the array after every significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = secure_maximum(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
