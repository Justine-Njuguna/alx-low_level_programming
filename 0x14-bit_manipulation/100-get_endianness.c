#include "main.h"

/**
 * get_endianness - Checks the endianness of the system
 *
 * Return: 0 if big endian else 1 if lil' endian
 */

int get_endianness(void)
{
	unsigned int num = 1;
	char *check_endian = (char *)&num;

	if (*check_endian)
		return (1);/* Lil' Endian */

	else
		return (0);/* Big endian */
}
