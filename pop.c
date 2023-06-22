#include "monty.h"
/**
 * pop - it removes the top element of the stack.
 * @stack: the double pointer to the head of the stack.
 * @line_number: its tne number in the Monty file.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
