#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer1;

	buffer1 = malloc(sizeof(char) * 1024);

	if (buffer1 == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer1);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from2, to2, r2, w2;
	char *buffer2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer2 = create_buffer(argv[2]);
	from2 = open(argv[1], O_RDONLY);
	r2 = read(from2, buffer2, 1024);
	to2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from2 == -1 || r2 == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer2);
			exit(98);
		}

		w2 = write(to2, buffer2, r2);
		if (to2 == -1 || w2 == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer2);
			exit(99);
		}

		r2 = read(from2, buffer2, 1024);
		to2 = open(argv[2], O_WRONLY | O_APPEND);

	} while (r2 > 0);

	free(buffer2);
	close_file(from2);
	close_file(to2);

	return (0);
}
