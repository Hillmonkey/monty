#include "monty.h"

/**
 * init_ops - initialize the global array of ops
 *
 **/
int init_ops(void)
{
	/* this needs to be  malloc'ed like printf */
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

}

/**
 * main - monty bytecode parser
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: int for EXIT_SUCCESS or EXIT_FAILURE
 **/

int main(int argc, char **argv)
{
	stack_t *stack;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1], glob);
	/* for line in file */
		/* I'm supposed to malloc for each line? */
		/* for MVP, I will have a buffer of pre-determined size */
	return (EXIT_SUCCESS);
}
