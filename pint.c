#include "monty.h"
#include <stdio.h>
/**
 * pint - it prints the value at the top of the stack.
 * @stack: the double pointer to the head of the stack.
 * @line_number: its the line number in the Monty file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
