#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	/* Get the integer argument for the push opcode */
	int arg;
	if (scanf("%d", &arg) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Create a new node */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = arg;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous node, if it exists */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack pointer */
	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

