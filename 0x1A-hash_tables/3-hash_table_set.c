#include "hash_tables.h"

/**
 * create_node - Creates a new node and duplicates key and value strings
 * @key: The key string
 * @value: The value associated with the key
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (NULL);

	/* Duplicate the key and value strings */
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_to_hash_table - Adds a new node to the hash table
 * @ht: The hash table to add the node to
 * @new_node: The new node to add
 * @index: The index at which the node should be added
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int add_node_to_hash_table(hash_table_t *ht,
		hash_node_t *new_node,
		unsigned long int index)
{
	/* Handle collision by adding new node at the beginning */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key string
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL, *temp = NULL;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	/* Calculate index for the given key */
	index = key_index((unsigned char *)key, ht->size);

	/* Check if key already exists, update its value */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			/* Free the existing value & update with new value */
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

	/* Create a new node and add it to the hash table */
	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	return (add_node_to_hash_table(ht, new_node, index));
}
