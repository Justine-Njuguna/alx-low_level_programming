#include "main.h"

/**
 * clear_bit - Sets the val of a bit to 0
 * @n: A ptr to the num whose bit is to be cleared
 * @index: The index (0) of the cleared bit
 *
 * Return: 1 on success else -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
