#include "main.h"

/**
 * allocate_buffer - Allocate memory for a buffer.
 * @file: The filename
 *
 * Return: A ptr to the allocated buffer.
 */

char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Custom Error: Unable to allocate memory for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_descriptor - Close a fd
 * @fd: The fd to be closed
 */

void close_descriptor(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Custom Error: Unable to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Custom Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Custom Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(destination_fd, buffer, read_bytes);
		if (destination_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Custom Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_descriptor(source_fd);
	close_descriptor(destination_fd);

	return (0);
}
