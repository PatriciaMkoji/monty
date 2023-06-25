#include "monty.h"
/**
 * mul_op - it multiplies the 2nd top element of the stack by the top element
 * @stack: its the double pointer to the top of the stack
 * @line_number: its being executed from the script file
 * Description: when stack contains less than 2 elements, prints an error
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= top->n;
	(*stack)->prev = NULL;
	free(top);
}
