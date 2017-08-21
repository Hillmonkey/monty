#include "monty.h"

/**
 * instruction_stack - sets the format of the doubly linked list to LIFO
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at?
 * Return: nothing
 **/
void instruction_stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	glob.isqueue = FALSE;
}

/**
 * instruction_queue - sets the format of the doubly linked list to FIFO
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at?
 * Return: nothing
 **/
void instruction_queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	glob.isqueue = TRUE;
}

