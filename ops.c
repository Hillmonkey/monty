#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));

	if (element == NULL || stack == NULL)
	{
		printf("L%ud: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	element->n = glob.push.operand;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
	return (element);
}
