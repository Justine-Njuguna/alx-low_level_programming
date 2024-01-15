#include "main.h"

/**
 * _isalpha - Checks if a char is alphabetic.
 * @c: The char to check.
 *
 * Return: 1 if c is alphabetic else 0.
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
