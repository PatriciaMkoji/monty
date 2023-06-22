#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: A double pointer to the top of the stack
 * @line_number: The line number of the instruction in the bytecode file
 *
 * Return: None
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
