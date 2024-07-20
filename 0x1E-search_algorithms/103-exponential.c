#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array
 *                  of integers using binary search.
 * @array: A pointer to the first element of the array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");

		for (i = left; i < right; i++)
			printf("%d, ", array[i]);

		if (left != right)
			printf("%d\n", array[right]);

		else
			printf("%d\n", array[left]);

		i = left + (right - left) / 2;

		if (array[i] == value)
			return (i);

		if (array[i] > value)
			right = i - 1;

		else
			left = i + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or if the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1;
	size_t right;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	/* Find range where value might be present */
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i = i * 2;
	}

	/* Define the range for binary search */
	right = (i < size) ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);

	return (_binary_search(array, i / 2, right, value));
}
