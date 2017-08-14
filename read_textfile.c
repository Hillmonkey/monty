#include "holberton.h"

/**
 * read_textfile - output contents of text file to STDOUT
 * @filename: string name of file (tested in CWD)
 * Return: figure out something good to return
 **/

/* ssize_t read_textfile(const char *filename, size_t letters) */
ssize_t read_textfile(const char *filename)
{
	ssize_t fd;
	ssize_t n = 0, n2;
	char *buf[1024];

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	n = read(fd, buf, letters);
	if (n == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	buf[n] = '\0';
	n2 = write(STDOUT_FILENO, buf, n);
	if (n2 == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}
	if (close(fd) < 0)
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (n);
}
