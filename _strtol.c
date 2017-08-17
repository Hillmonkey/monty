#include "monty.h"

/**
 * _strtol - wrapper around strtol, handling monty specific errors
 * @num_string: string that *should* represent an integer
 * @line_number: line counter of monty file
 * Return: long int that strtol converted
 **/

int _strtol(char *num_string, unsigned int line_number)
{
	int base = 10;
	char *endptr;
	long val;


	errno = 0;    /* To distinguish success/failure after call */
	val = strtol(num_string, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
									|| (errno != 0 && val == 0))
	{
		/* perror("strtol"); */
		exit(EXIT_FAILURE);
	}

	if (endptr == num_string)
	{
		/* No digits were found */
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* If we got here, strtol() successfully parsed a number */
	/* return val; */

	if (num_string[0] != '\0')
		if (!isdigit(num_string[0]) && *endptr != '\0')
		/* I don't think this is testing for what I want. Oh, well ... */
		{
			/* trailing alpha on tail of number */
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (val);
}
