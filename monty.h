#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define DELIMS "/n /t/r"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @push_operand: push needs data outside of its proscribed prototype
 **/
typedef struct glob_s
{
	stack_t *top;
	char *token[2];
	/* instruction_t *ops[] */
} glob_t;

extern glob_t *glob;

/* helper1.c */
int process_file(char *filename, stack_t **stack);

/* helper2.c */
int delegate_op(stack_t **stack, char *op, char *operand,
				unsigned int line_number);

/* instruction.c */
void instruction_push(stack_t **stack, unsigned int line_number);
void instruction_pop(stack_t **stack, unsigned int line_number);
void instruction_pint(stack_t **stack, unsigned int line_number);
void instruction_pall(stack_t **stack, unsigned int line_number);
void instruction_swap(stack_t **stack, unsigned int line_number);

/* instruction2.c */
void instruction_add(stack_t **stack, unsigned int line_number);
void instruction_nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY */
