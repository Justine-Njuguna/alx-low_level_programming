#include "main.h"

/**
 * print_usage_error - Prints a usage error message.
 * @program_name: The name of the program.
 */

void print_usage_error(char *program_name)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
}

/**
 * copy_file_content - Copies the content from one fd to another
 * @fd_from: The source fd
 * @fd_to: The destination fd
 *
 * Return: 0 on success else -1
 */

int copy_file_content(int fd_from, int fd_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			return (-1);
	}

	if (bytes_read == -1)
		return (-1);

	return (0);
}

/**
 * close_file - Closes a fd and handles errors.
 * @fd: The fd to close.
 *
 * Return: 0 on success, else -1.
 */

int close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		return (-1);
	}

	return (0);
}

/**
 * main - Entry.
 * @argc: The num of CLI args.
 * @argv: An array of CLI strings
 *
 * Return: 0 on success else an error code
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		print_usage_error(argv[0]);
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		return (99);
	}

	if (copy_file_content(fd_from, fd_to) == -1)
	{
		close(fd_from);
		close(fd_to);
		return (99);
	}

	if (close_file(fd_from) == -1)
		return (100);

	if (close_file(fd_to) == -1)
		return (100);

	return (0);
}
