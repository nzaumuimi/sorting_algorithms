#include "sort.h"

void combine_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void combine_org_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * combine_subarr - Sorts a subarray of ints.
 * @subarr: The subarray of an array of ints to be sorted.
 * @buff: The location of te buff to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void combine_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * combine_org_recursive - Operationalises the merge sort
 * algos by recursion.
 * @subarr: The subarray of an array of ints to sort.
 * @buff: A buff where  the sorted results are stored.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void combine_org_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		combine_org_recursive(subarr, buff, front, mid);
		combine_org_recursive(subarr, buff, mid, back);
		combine_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of ints in ascending
 * order using the merge sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Operationazises the top-down merge sort algo.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	combine_org_recursive(array, buff, 0, size);

	free(buff);
}
