#include "monty.h"

/**
 * main - monty bytecode parser
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: int for EXIT_SUCCESS or EXIT_FAILURE
 **/

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	/* for line in file */
		/* I'm supposed to malloc for each line? */
		/* for MVP, I will have a buffer of pre-determined size */
	return (EXIT_SUCCESS);
}
