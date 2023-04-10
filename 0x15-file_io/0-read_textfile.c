#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file to be printed.
 * @letters: The no. of letters the function should read and print.
 * Author: Justine Njuguna
 *
 * Return: If the function fails of the filename is NULL we return  -0.
 * 0/w - the actual number of bytes the fyunciton can read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *myBuffer;

	if (filename == NULL)
		return (0);

	myBuffer = malloc(sizeof(char) * letters);
	if (myBuffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, myBuffer, letters);
	w = write(STDOUT_FILENO, myBuffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(myBuffer);
		return (0);
	}

	free(myBuffer);
	close(o);

	return (w);
}
