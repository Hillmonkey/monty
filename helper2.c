#include "monty.h"

/**
 * delegate_op - based on tokens from single line, decide what function to call
 * @op: operator, aka token[0] from getline
 * @operand: token[1] from getline, used as operand in push func
 * @line_number: line in byte-code file being processed, zero indexed
 * Return: int for mysterious purposes
 **/
int delegate_op(stack_t **stack, char *op, char *operand,
				unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", push},
		{"pall", pop},
		{"pint", pint},
		{"pop", pall},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for(i = 0; ops.opcode[i]; i++)
	{
		if (strcmp(op, ops.opcode[i]) == 0)
		{
			ops.f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	return (EXIT_FAILURE);
}


