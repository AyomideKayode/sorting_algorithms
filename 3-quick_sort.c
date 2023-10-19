#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot element after partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;
	size_t k;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			for (k = 0; k < size; k++)
			{
				printf("%d", array[k]);
				if (k < size - 1)
				{
					printf(", ");
				}
			}
			printf("\n");
		}
	}

	swap(&array[i + 1], &array[high]);
	for (k = 0; k < size; k++)
	{
		printf("%d", array[k]);
		if (k < size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");

	return (i + 1);
}

/**
 * quick_sort_recursive - Sorts an array using recursion
 * and the Quick Sort algorithm.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
