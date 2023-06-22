#include "monty.h"
/**
 * swap - it swaps the top 2 elements of the stack.
 * @stack: the double pointer to the head of the stack.
 * @line_number: its the line number in the Monty file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
