#include "main.h"

/**
 * flip_bits - Returns the num of bits needed to flip
 * @n: The first num
 * @m: The second num
 *
 * Return: The num of bits needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}
