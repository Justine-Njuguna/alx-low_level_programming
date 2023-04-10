#include "main.h"

/**
 * create_file: Creates a file.
 * @filename: Name of the file to create -> pointer.
 * @text_content: Is a NULL terminated string to write to the file.
 *
 * Return: if filename is NULL, return -1
 * if text_content is NULL, create an empty file.
 */

int create_file(const char *filename, char *text_content)
{
	int o, w, length = 0;

	if (filename ==  NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, length);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
