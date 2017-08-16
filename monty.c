#include "monty.h"

void stack_init(stack_t **head)
{
	*head = NULL
}

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
