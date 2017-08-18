#include "monty.h"

/**
 * instruction_add - adds top 2 elements of the stack
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_add(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	int n_1, n_2;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n_1 = (*stack)->n;
	instruction_pop(stack, line_number);
	n_2 = (*stack)->n;
		instruction_pop(stack, line_number);
	element->n = n_1 + n_2;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * instruction_nop - doesn't do anything
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * instruction_sub - substracts top element from second top element
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	int n_1, n_2;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n_1 = (*stack)->n;
	instruction_pop(stack, line_number);
	n_2 = (*stack)->n;
	instruction_pop(stack, line_number);
	element->n = n_2 - n_1;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * instruction_div - divides second top element from top element
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_div(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	int n_1, n_2;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n_1 = (*stack)->n;
	instruction_pop(stack, line_number);
	n_2 = (*stack)->n;
	instruction_pop(stack, line_number);
	element->n = n_2 / n_1;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * instruction_mul - multiplies second top element from top element
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	int n_1, n_2;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n_1 = (*stack)->n;
	instruction_pop(stack, line_number);
	n_2 = (*stack)->n;
	instruction_pop(stack, line_number);
	element->n = n_2 * n_1;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}
