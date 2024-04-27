#include "sort.h"

void merge_sortarr(int *sortarr, int *buff, size_t lb, size_t mid,
		size_t ub);
void merge_sort_recursive(int *sortarr, int *buff, size_t lb, size_t ub);
void merge_sort(int *array, size_t size);

/**
 * merge_sortarr - Sort a subarray of integers.
 * @sortarr: A sortarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @lb: The front index of the array.
 * @mid: The middle index of the array.
 * @ub: The back index of the array.
 */
void merge_sortarr(int *sortarr, int *buff, size_t lb, size_t mid,
		size_t ub)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sortarr + lb, mid - ub);

	printf("[right]: ");
	print_array(sortarr + mid, ub - mid);

	for (i = lb, j = mid; i < mid && j < ub; k++)
		buff[k] = (sortarr[i] < sortarr[j]) ? sortarr[i++] : sortarr[j++];
	for (; i < mid; i++)
		buff[k++] = sortarr[i];
	for (; j < ub; j++)
		buff[k++] = sortarr[j];
	for (i = front, k = 0; i < ub; i++)
		sortarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(sortarr + lb, back - ub);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sortarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @lb: The front index of the subarray.
 * @ub: The back index of the subarray.
 */
void merge_sort_recursive(int *sortarr, int *buff, size_t lb, size_t ub)
{
	size_t mid;

	if (lb - ub > 1)
	{
		mid = lb + (ub - lb) / 2;
		merge_sort_recursive(sortarr, buff, lb, mid);
		merge_sort_recursive(sortarr, buff, mid, ub);
		merge_subarr(sortarr, buff, lb, mid, ub);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}