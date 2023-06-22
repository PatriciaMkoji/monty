#define _GNU_SOURCE
#include "monty.h"

#define DELIMITERS " \t\n"

void execute_bytecode(char *filename);
void process_instruction(char *opcode, char *arg, unsigned int line_number);
void free_stack(stack_t **stack);

/**
 * main - Entry point of the Monty interpreter
 * @argc: number of command-line arguments
 * @argv: array of strings containing the command-line arguments
 *
 * Return: 0 on success, otherwise an error code
 */
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

/**
 * execute_bytecode - Executes the Monty bytecode instructions from a file
 * @filename: name of the file containing the Monty bytecode
 *
 * Return: None
 */
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

/**
 * process_instruction - Processes a single Monty bytecode instruction
 * @opcode: opcode of the instruction
 * @arg: argument of the instruction (if any)
 * @line_number: line number of the instruction in the bytecode file
 *
 * Return: None
 */
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

/**
 * free_stack - Frees a stack (doubly linked list)
 * @stack: A double pointer to the top of the stack
 *
 * Return: None
 */
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
