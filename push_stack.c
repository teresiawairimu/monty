#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

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
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	v = atoi(i);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = v;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev->new_node;
	*stack = new_node;
}
