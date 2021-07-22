#include "sort.h"

/**
 * shell_sort - Shell sort algorithm using Knuth sequence
 * @array: Array
 * @size: Size of the array
 * Return:
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp, make_sort;

	for (gap = 1; gap < size; gap = (gap * 3) + 1)
		;

	while (gap > 0)
	{
		make_sort = 0;
		for (i = gap; i < size; i++)
		{
			j = i;
			temp = array[i];
			while ((j >= gap) && (array[j - gap] > temp))
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
			make_sort = 1;
		}
		if (make_sort == 1)
			print_array(array, size);
		gap = gap / 3;
	}
}
