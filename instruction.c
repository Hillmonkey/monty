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

	printf("TOMMYTOMMY-PUSHPUSHPUSH\n");
	oper = strtok(NULL, DELIMS);
	if (oper == NULL || element == NULL || stack == NULL)
	{
		printf("L%ud: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(oper);
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

	printf("TOMMYTOMMY-PALLPALLPALL\n");
	while (stack != NULL)
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

	printf("TOMMYTOMMY-PINTPINTPINT\n");
	if (element == NULL || stack == NULL)
	{
		printf("L%ud: can't pint, stack empty", line_number);
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
	stack_t *element = *stack;

	printf("TOMMYTOMMY-POPPOPPOPPOP\n");
	if (element == NULL || stack == NULL)
	{
		printf("L%ud: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	free(element);
}

/**
 * instruction_swap - swaps 2 elements of the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 */
void instruction_swap(stack_t **stack, unsigned int line_number)
{

	printf("TOMMYTOMMY-SWAPSWAPSWAP\n");
	(void)line_number;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->prev = NULL;
}
