#include "main.h"

/**
 * custom_check97 - Check for the correct number of arguments.
 * @argc: Num of args
 *
 * Return: void.
 */

void custom_check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Custom Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * custom_check_read - Check if file_from exists and can be read.
 * @check: Check if true or false
 * @file: file_from name
 * @fd_from: File descriptor of file_from, or -1
 *
 * Return: void.
 */

void custom_check_read(ssize_t check, char *file, int fd_from)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Custom Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		exit(98);
	}
}

/**
 * custom_check_write - Check if file_to was created and/or can be written to.
 * @check: Check if true or false.
 * @file: file_to name
 * @fd_to: File descriptor of file_to, or -1
 *
 * Return: void
 */

void custom_check_write(ssize_t check, char *file, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Custom Error: Can't write to %s\n", file);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * custom_check_close - Check that file descriptor was closed properly.
 * @check: Check if true or false
 * @fd: File descriptor
 *
 * Return: void
 */

void custom_check_close(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Custom Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: Number of arguments passed
 * @argv: Array of pointers to the arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	custom_check97(argc);
	fd_from = open(argv[1], O_RDONLY);
	custom_check_read((ssize_t)fd_from, argv[1], -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	custom_check_write((ssize_t)fd_to, argv[2], fd_from);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, buffer, 1024);
		custom_check_read(lenr, argv[1], fd_from);
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		custom_check_write(lenw, argv[2], fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	custom_check_close(close_to, fd_to);
	custom_check_close(close_from, fd_from);
	return (0);
}
