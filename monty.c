#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		/* Tokenize the line to get the opcode and argument */
		char *opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue; /* Ignore empty lines and comments */

		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(line);
				fclose(file);
				free_stack(&stack);
				return EXIT_FAILURE;
			}
			push(&stack, line_number, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			free_stack(&stack);
			return EXIT_FAILURE;
		}
	}

	free(line);
	fclose(file);
	free_stack(&stack);

	return EXIT_SUCCESS;
}

