#include "monty.h"

/**
 *
 **/
void instruction_add(stack_t **stack, unsigned int line_number)
{
	printf("ADD:stack-pointer->%p line-num->%u\n", (void *)stack, line_number);
}

/**
 *
 **/
void instruction_nop(stack_t **stack, unsigned int line_number)
{
	printf("NOP:stack-pointer->%p line-num->%u\n", (void *)stack, line_number);
}

