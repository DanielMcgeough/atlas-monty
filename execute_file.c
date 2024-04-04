#include "monty.h"
stack_t *stack_top = NULL;

void execute_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == "#")
		{
			continue;
		}
		void (*func)(stack_t **, unsigned int) = get_function(opcode);
		func(&stack_top, line_number);
	}
	free(line);
}