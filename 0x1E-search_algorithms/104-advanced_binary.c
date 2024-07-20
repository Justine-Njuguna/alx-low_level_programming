#include "search_algos.h"

/**
 * print_subarray - Prints the subarray from index `left` to `right`.
 *
 * @array: A pointer to the first element of the array.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 */
void print_subarray(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array");

	for (i = left; i < right; i++)
		printf("%s %d", (i == left) ? ":" : ",", array[i]);

	printf("%s %d\n", (i == left) ? ":" : ",", array[i]);
}

/**
 * rec_search - Searches for a value in a sorted array using recursion.
 *
 * @array: A pointer to the first element of the array.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: The index where the value is located or -1 if not found.
 */
int rec_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right || array == NULL)
		return (-1);

	print_subarray(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		/* Check if this is the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (rec_search(array, left, mid - 1, value));
	}

	if (array[mid] < value)
		return (rec_search(array, mid + 1, right, value));

	else
		return (rec_search(array, left, mid - 1, value));
}

/**
 * advanced_binary - Calls rec_search to find the index of the value.
 *
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (rec_search(array, 0, size - 1, value));
}
