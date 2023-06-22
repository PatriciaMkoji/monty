#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *arg = strtok(NULL, " \t\n");

	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
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

/**
 * is_integer - Checks if a string is a valid integer
 * @str: The string to check
 * Return: 1 if it is an integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;

		free(temp);
	}
}

