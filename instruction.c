#include "monty.h"

/**
 *
 **/
void instruction_push(stack_t **stack, unsigned int line_number)
{
	printf("POP:stack-pointer->%p line-num->%u\n", stack, line_number);
}

/**
 *
 **/
void instruction_pop(stack_t **stack, unsigned int line_number)
{
	printf("PUSH:stack-pointer->%p line-num->%u\n", stack, line_number);
}

/**
 *
 **/
void instruction_pint(stack_t **stack, unsigned int line_number)
{
	printf("PULL:stack-pointer->%p line-num->%u\n", stack, line_number);
}

/**
 *
 **/
void instruction_pall(stack_t **stack, unsigned int line_number)
{
	printf("PINT:stack-pointer->%p line-num->%u\n", stack, line_number);
}

/**
 *
 **/
void instruction_swap(stack_t **stack, unsigned int line_number)
{
	printf("ADD:stack-pointer->%p line-num->%u\n", stack, line_number);
}
