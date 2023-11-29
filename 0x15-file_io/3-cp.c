#include "main.h"

/**
 * create_buffer - Allocate memory for a buffer.
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
	int from_fd, to_fd;
	ssize_t read_bytes, write_bytes;
	char *buffer;
	mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from_fd = open(argv[1], O_RDONLY);
	check_error(from_fd, argv[1], -1, -1, 98);
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_error(to_fd, argv[2], from_fd, -1, 99);

	do {
		read_bytes = read(from_fd, buffer, 1024);
		check_error(read_bytes, argv[1], from_fd, to_fd, 98);

		write_bytes = write(to_fd, buffer, read_bytes);
		check_error(write_bytes, argv[2], from_fd, to_fd, 99);
	} while (read_bytes > 0);

	free(buffer);

	close_fd(from_fd, argv[1]);
	close_fd(to_fd, argv[2]);

	return (0);
}

/**
 * check_error - Checks for errors in file ops and exits if necessary.
 * @check: The result to be checked.
 * @file: The name of the file associated with the operation.
 * @fd_from: The fd of file_from, or -1.
 * @fd_to: The fd of file_to
 * @code: The exit code if error detected
 *
 * Return: void.
 */

void check_error(int check, const char *file, int fd_from, int fd_to, int code)
{
        if (check == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't %s from file %s\n", (code == 98) ? "read" : "write", file);
                if (fd_from != -1)
                        close_fd(fd_from, file);
                if (fd_to != -1)
                        close_fd(fd_to, file);
                exit(code);
        }
}
