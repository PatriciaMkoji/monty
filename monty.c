#define _GNU_SOURCE
#include "monty.h"

#define DELIMITERS " \t\n"

void execute_bytecode(char *filename);
void process_instruction(char *opcode, char *arg, unsigned int line_number);
void free_stack(stack_t **stack);

int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	execute_bytecode(filename);

	return (EXIT_SUCCESS);
}

void execute_bytecode(char *filename)
{
	FILE *file;
	char *line;
	size_t line_size;
	unsigned int line_number;
	char *opcode;
	char *arg;
	stack_t *stack;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	line = NULL;
	line_size = 0;
	line_number = 0;

	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		arg = strtok(NULL, DELIMITERS);

		if (opcode != NULL)
		{
			process_instruction(opcode, arg, line_number);
		}
	}

	free(line);
	free_stack(&stack);
	fclose(file);
}

void process_instruction(char *opcode, char *arg, unsigned int line_number)
{
	int value;
	stack_t *stack;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		value = atoi(arg);
		push(&stack, line_number, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(&stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(&stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}
