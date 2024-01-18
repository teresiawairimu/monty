#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * process_file - processes the file containing monty byte code
 * @file: the name of the monty file
 * Parameter 'file' is intentionally unused.
 */
__attribute__((unused)) void process_file(const char *file)
{
	FILE *ptr;
	char *l;
	size_t length;
	unsigned int line_number;
	char *opcode;
	const instruction_t *instructions;
	
	
	ptr = fopen(file, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	l = NULL;
	length = 0;
	line_number = 0;
	while (getline(&l, &length, ptr) != -1)
	{
		line_number++;
		printf("Line %u: %s", line_number, l);
		opcode = strtok(l, " \t\n");
		if (opcode != NULL)
		{
			for (instructions = new_instructions; instructions->opcode != NULL; instructions++)
			{
				if (strcmp(opcode, instructions->opcode) == 0)
				{
					instructions->f(&new_stack, line_number);
					break;
				}
			}
		}
	}
	fclose(ptr);
	free(l);
}
