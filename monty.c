#define _GNU_SOURCE
#include "monty.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
        size_t line_len = 0;
        ssize_t read;
	FILE *file;
	stack_t *stack;
	char *opcode;
	char *arg;
	unsigned int line_number = 0;
	void (*func)(stack_t **, unsigned int) = NULL;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty byte code file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Initialize the stack */
	stack = NULL;



	/* Get the function corresponding to the opcode */

	while ((read = getline(&line, &line_len, file)) != -1)
	{
		line_number++;

		/* Tokenize the line to extract the opcode and argument */
		opcode = strtok(line, " \t\n");

		/* Skip empty lines and comments */
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
			func = push;
		else if (strcmp(opcode, "pall") == 0)
			func = pall;
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}

		/* Execute the function with the provided argument (if any) */
		arg = strtok(NULL, " \t\n");
		if (func == push && (arg == NULL || !is_integer(arg)))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(stack);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}

		/* Call the function */
		func(&stack, line_number);
	}

	/* Clean up */
	free_stack(stack);
	fclose(file);
	free(line);

	return EXIT_SUCCESS;
}

/* Rest of the code remains the same */


