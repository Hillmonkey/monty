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
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *token[2];

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
		printf("%s", line);
		/* do these need to be malloc'ed for ??? */
		glob->token[0] = strtok(line, DELIMS);
		glob->token[1] = strtok(NULL, DELIMS);
		printf("<TOKEN1> %s <TOKEN2> %s <--\n", glob->token[0], glob->token[1]);
		delegate_op(line_number);
		line_number++;
		/* printf("Retrieved line of length %lu\n", read); */
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
