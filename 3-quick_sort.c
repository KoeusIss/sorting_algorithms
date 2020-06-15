#include "sort.h"

/**
 * swap - swaps two integers
 * @first: first integer
 * @second: second integer
 *
 * Return: void
 */
void swap(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * partition - partitions an array seperate by pivot
 * @array: the given array
 * @low: the lowest value of the array
 * @high: the highest value of the array
 *
 * Return: the pivot position as integer
 */
int partition(int *array, size_t size)
{
	size_t pivot = size - 1;
	size_t i = 0, j;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= array[pivot])
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[size - 1]);
	return (i);
}

/**
 * quick_sort - sorts recursively an array of integer
 * @array: the given array of integer
 * @low: the lowest value of the array
 * @high: the highest value of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t prt;

	prt = partition(array, size);
	if (prt > 1)
		quick_sort(array, prt - 1);
	if (prt < size - 2)
		quick_sort(array + prt + 1, size - 1 - prt);
	print_array(array, size);
}
