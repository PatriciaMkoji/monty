#include "monty.h"
/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: the double pointer to the top of the stack
 * @line_number: will be line number being executed from the script file
 * Description: will stack contains less than two elements, prints an error
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= top->n;
	(*stack)->prev = NULL;
	free(top);
}

