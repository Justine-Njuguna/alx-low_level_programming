#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: A ptr to the newly created hash table else NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	unsigned long int i;

	/* Allocate memory for the hash table struct */
	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	/* Allocate memory for the array of hash nodes */
	hash_table->array = malloc(size * sizeof(hash_node_t *));
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	/* Init each element of the array to NULL */
	for (i = 0; i < size; i++)
	{
		hash_table->array[i] = NULL;
	}

	hash_table->size = size;

	return (hash_table);
}
