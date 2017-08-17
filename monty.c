#include "monty.h"

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
}

/**
 * main - monty bytecode interpreter
 * @argc: number of command line arguments
 * @argv: array of strings containing the comm line args
 * Return: EXIT_SUCCESS or EXIT_FAILURE!!!
 **/
int main(int argc, char **argv)
{
	stack_t *head;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack_init(&head);
	process_file(argv[1], &head);
	/* for line in file */
		/* I'm supposed to malloc for each line? */
		/* for MVP, I will have a buffer of pre-determined size */
	return (EXIT_SUCCESS);
}
