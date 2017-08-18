#include "monty.h"

/**
 * instruction_push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *oper;
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	oper = strtok(NULL, DELIMS);
	if (oper == NULL || stack == NULL)
	{
		printf("L%ud: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(oper, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * instruction_pall - prints all values on the stack, starting from top
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;
	(void)(line_number);

	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}

/**
 * instruction_pint - prints value at top of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	if (element == NULL || stack == NULL)
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", element->n);
}

/**
 * instruction_pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

/**
 * instruction_swap - swaps 2 elements of the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 */
void instruction_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!(*stack) || !((*stack)->next))
	{
		printf("L%ud: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}
