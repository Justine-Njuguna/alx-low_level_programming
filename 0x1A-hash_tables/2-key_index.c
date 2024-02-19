#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in the hash table array
 * @key: The key string
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key should be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* Calculate the hash value using hash_djb2 function */
	hash_value = hash_djb2(key);

	/* Calculate the index within the array */
	return (hash_value % size);
}
