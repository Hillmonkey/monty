#include "monty.h"

/**
 * process_file - process the whole monty file
 * @filename: str name of monty opcode file
 * Return: return an error code or success
 **/
int process_file(char *filename)
{
	size_t len;
	ssize_t read;
	char *line = NULL;
	FILE *fp;

	if (!filename)
	{
		printf("Error: Can't open file (nil)\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		/* printf("Retrieved line of length %lu\n", read); */
		printf("%s", line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
