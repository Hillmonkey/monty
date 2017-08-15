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
}

/**
 * pall - prints all values on the stack, starting from top
 * @h: beginning of stack
 * Return: nothing
 */
void pall(stack_t *h)
{
	stack_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
}

/**
 * pop - prints value at top of stack
 * @h: beginning of stack
 * Return: nothing
 */
void pint(stack_t *h)

	printf("%d\n", h->n);
