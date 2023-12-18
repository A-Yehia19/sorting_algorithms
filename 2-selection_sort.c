#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The list to be printed
 * @size: Number of elements in @array
 * Return: NONE
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int tmp;

	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i; j < size; j++)
			if (array[j] < array[index])
				index = j;

		if (index != i)
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
