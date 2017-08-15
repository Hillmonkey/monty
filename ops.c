#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */

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
