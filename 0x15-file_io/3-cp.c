#include "main.h"

/**
 * create_buffer - Allocate memory for a buffer.
 * @file: Name of the file.
 *
 * Return: A pointer to the allocated buffer.
 */

char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);

	if (buffer == NULL)
	{
		perror("Error: Can't allocate memory");
		exit(98);
	}
	return (buffer);
}

/**
 * close_fd - Close a file descriptor.
 * @fd: The file descriptor to be closed.
 * @file: Name of the file associated with the descriptor.
 *
 * Return: void.
 */

void close_fd(int fd, const char *file)
{
	int close_status;

	close_status = close(fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd for %s\n", file);
		exit(100);
	}
}

/**
 * main - Copy the contents of one file to another.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, other values on failure.
 */

int main(int argc, char *argv[])
{
	int from_fd, to_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from_fd = open(argv[1], O_RDONLY);
	read_bytes = read(from_fd, buffer, 1024);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file%s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		write_bytes = write(to_fd, buffer, read_bytes);
		if (to_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		read_bytes = read(from_fd, buffer, 1024);
		to_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_bytes > 0);

	free(buffer);
	close_fd(from_fd, argv[1]);
	close_fd(to_fd, argv[2]);

	return (0);
}
