#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - check the code
 * @argc: stores the number of command-line arguments
 * @argv: array of character pointers listing all arguments
 *
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *new_stack;
	instructions_t new_instructions[] = {
		{"push", push_stack},
		{"pall", pall_stack}
	};
	char *l = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int i;
	FILE *ptr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	new_stack = NULL;
	while (getline(&l, &len, ptr) != -1)
	{
		line_number++;
		for (i = 0; new_instructions[i].opcode != NULL; i++)
		{
			if (strcmp(l, new_instructions[i].opcode) == 0)
			{
				new_instructions[i].f(&new_stack, line_number);
				break;
			}
		}
	}
	free(l);
	fclose(ptr);
	free(new_stack);
	return (EXIT_SUCCESS);
}
