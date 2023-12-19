#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 * Return: NONE
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Lomuto partition scheme
 * @array: The list to be printed
 * @start: Starting index
 * @end: Ending index
 * @size: Number of elements in array
 * Return: Partition index
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot;
	int pi, i;

	pi = start;
	pivot = array[end];
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[pi]);
			pi++;
			print_array(array, size);
		}
	}

	/* put pivot on the right place */
	if (array[pi] > pivot)
	{
		swap(&array[pi], &array[end]);
		print_array(array, size);
	}
	return (pi);
}

/**
 * quick_sort_rec - Quick sort algorithm
 * @array: The list to be printed
 * @start: Starting index
 * @end: Ending index
 * @size: Number of elements in array
 * Return: NONE
 */
void quick_sort_rec(int *array, int start, int end, size_t size)
{
	int pi;

	if (start < end)
	{
		pi = partition(array, start, end, size);
		quick_sort_rec(array, start, pi - 1, size);
		quick_sort_rec(array, pi + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The list to be printed
 * @size: Number of elements in @array
 * Return: NONE
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
