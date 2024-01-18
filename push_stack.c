#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * extract - skips non-numeric characters
 * @str: pointer to a constant character
 * Return: integer
 */
int extract(const char *str)
{
	int result;
	const char *position;
	size_t new_length;
	char *new_str;
	char *ptr;
	long answer;

	position = strchr(str, '$');
	if (position != NULL)
	{
		new_length = position-str+2;
		new_str = malloc(new_length+1);
		if (new_str == NULL)
		{
			fprintf(stderr, "Error:malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strncpy(new_str, str, position-str);
		new_str[position-str] = ' ';
		strcpy(new_str+(position-str)+1,position+1);
		answer = strtol(new_str, &ptr, 10);
		if (*ptr != '\0' && !isspace((unsigned char)*ptr))
		{
			fprintf(stderr, "Coversion Error\n");
			exit(EXIT_FAILURE);
		}
		result = (int)answer;
		free(new_str);
	}
	else
	{
		answer = strtol(str, &ptr, 10);
		if (*ptr != '\0' && !isspace((unsigned char)*ptr))
		{
			fprintf(stderr, "Conversion error\n");
			exit(EXIT_FAILURE);
		}
		result = (int)answer;
	}
	return (result);
}
/**
 * push - add a new element at the beginning of the stack
 * @stack: pointer to the pointer of the head of the stack
 * @line_number: the line number in the monty code file
 *
 * Return: has no return value
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int v;
	char *i;

	i = strtok(NULL, " \t\n");
	if (i == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("Token: %s\n", i);
	v = extract(i);
	printf("Pushing value: %d at line %u\n", v, line_number);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = v;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
