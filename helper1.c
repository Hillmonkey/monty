#include "monty.h"

/**
 * process_file - process the whole monty file
 * @filename: str name of monty opcode file
 * Return: return an error code or success
 **/
int process_file(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *oper, *operand = NULL;


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
		oper = strndup(strtok(line, DELIMS), 128);
		if (operator != NULL)
			operand = strdup(strtok(NULL, DELIMS));
		/* how does printf deal with printing a NULL pointer? */
		printf("<TOKEN1> %s <TOKEN2> %s <--\n", operator, operand);
		line_number++;
		delegate_op(stack, oper, operand, line_number);
		free(oper);
		free(operand);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
