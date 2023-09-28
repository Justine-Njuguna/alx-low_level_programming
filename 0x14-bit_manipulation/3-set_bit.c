#include "main.h"

/**
 * set_bit - Sets the val of a bit to 1 at an index
 * @n: A ptr to the num whose bit is set
 * @index: Index(starting from 0) of the bit to set
 *
 * Return: 1 on success else -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
