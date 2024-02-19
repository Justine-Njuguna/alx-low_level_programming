#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key you are looking for
 *
 * Return: The val associated with the element | NULL if key not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Calculate index for the given key */
	index = key_index((unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	temp = ht->array[index];
	while (temp != NULL)
	{
		/* Check if the key matches */
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	/* Key not found */
	return (NULL);
}
