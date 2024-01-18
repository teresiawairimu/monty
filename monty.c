#define _POSIX_C_SOURCE 200809L
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
stack_t *new_stack = NULL;
const instruction_t new_instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	return (0);
}
