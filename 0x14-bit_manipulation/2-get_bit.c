#include "main.h"

/**
 * get_bit - Returns the val of a bit at a given index
 * @n: The num whose bit is gotten
 * @index: The index (from 0) of the bit to get
 *
 * Return: Val of the bit at 'index' else 1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return ((n >> index) & 1);
}
