#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * push - t pushes an element to the stack.
 * @stack: the double pointer to the head of the stack.
 * @line_number: its the line number in the Monty file.
 * @value: Integer value to be pushed.
 */
void push(stack_t **stack, unsigned int line_number,  int value)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	/* free(new_node); */
}
