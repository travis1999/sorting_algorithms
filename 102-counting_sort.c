#include "sort.h"

/**
 * counting_sort - counting
 * desc: using the counting sort algorithm
 * @array: array
 * @size: size
 */
void counting_sort(int *array, size_t size)
{
	int max = max_num(array, size);
	int range = max + 1;
	int *count = malloc(sizeof(int) * range);
	int *output = malloc(sizeof(int) * size);
	int i = 0;

	if (!count && !output)
		return;
	if (!count && output)
	{
		free(output);
		return;
	}
	if (count && !output)
	{
		free(count);
		return;
	}
	for (i = 0; i < range; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		++count[array[i]];

	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	print_array(count, range);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}

/**
 * max_num - get the maximun number
 * @array: array
 * @size: size
 * Return: Maximun number of @array
 */
int max_num(int *array, size_t size)
{
	size_t i;
	int max;

	if (size == 0)
		return (0);

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
